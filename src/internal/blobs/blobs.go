package blobs

import (
	"bufio"
	"bytes"
	"fmt"
	"os"
	"regexp"
	"strconv"
)

const (
	memmapC   = "memmap.c"
	memmapGo1 = "memmap.go"
	memmapGo2 = "common/memmap/nox/noxmap.go"
	dataC     = "GAME_data.c"
)

var (
	reDataC = regexp.MustCompile(`unsigned\s+char\s+byte_([A-Fa-f\d]+)\[(\d+)\]\s*=\s*`)
	reExtC  = regexp.MustCompile(`extern\s+unsigned\s+char\s+byte_([A-Fa-f\d]+)\[(\d+)\]\s*;\n`)
	reMapC  = regexp.MustCompile(`[ \t]*case 0x([A-Fa-f\d]+):\s+if\s+\(off\+size\s*<=\s*sizeof\(byte_([A-Fa-f\d]+)\)\)\s*\{?\s*return\s+&byte_([A-Fa-f\d]+)\[off\]\s*;(?:\s*\})?\n`)
	reMapG1 = regexp.MustCompile(`[ \t]*memmap\.RegisterBlobData\(0x([A-Fa-f\d]+), "byte_([A-Fa-f\d]+)", unsafe\.Slice\(\(\*byte\)\(unsafe\.Pointer\(&C\.byte_([A-Fa-f\d]+)\[0\]\)\), int\(unsafe\.Sizeof\(C\.byte_([A-Fa-f\d]+)\)\)\)\)\n`)
	reMapG2 = regexp.MustCompile(`[ \t]*memmap\.RegisterBlob\(0x([A-Fa-f\d]+), "byte_([A-Fa-f\d]+)", (\d+)\)\n`)
)

type Blob struct {
	Blob uintptr
	Size uintptr
	Data []byte
}

// ReadBlobs reads and allows to modify the blob list.
func ReadBlobs() (*Blobs, error) {
	b := new(Blobs)
	if err := b.readMemmapGo1(); err != nil {
		return nil, err
	}
	if err := b.readMemmapGo2(); err != nil {
		return nil, err
	}
	if err := b.readMemmapC(); err != nil {
		return nil, err
	}
	if err := b.readData(); err != nil {
		return nil, err
	}
	return b, nil
}

type Blobs struct {
	data struct {
		pre   []byte
		blobs []Blob
		post  []byte
	}
	mapc struct {
		pre    []byte
		blobs1 []Blob
		mid    []byte
		blobs2 []Blob
		post   []byte
	}
	mapg1 struct {
		pre    []byte
		blobs1 []Blob
		mid    []byte
		blobs2 []Blob
		post   []byte
	}
	mapg2 struct {
		pre   []byte
		blobs []Blob
		post  []byte
	}
}

func (b *Blobs) get(blob uintptr, arr []Blob) *Blob {
	for _, v := range arr {
		if v.Blob == blob {
			return &v
		}
	}
	return nil
}

// Get blob with a given base address.
func (b *Blobs) Get(blob uintptr) *Blob {
	// with actual data
	if v := b.get(blob, b.data.blobs); v != nil {
		return v
	}
	// no data, but have sizes
	if v := b.get(blob, b.mapg1.blobs1); v != nil {
		return v
	}
	if v := b.get(blob, b.mapg2.blobs); v != nil {
		return v
	}
	if v := b.get(blob, b.mapc.blobs1); v != nil {
		return v
	}
	// only the base address
	if v := b.get(blob, b.mapg1.blobs2); v != nil {
		return v
	}
	if v := b.get(blob, b.mapc.blobs2); v != nil {
		return v
	}
	return nil
}

func (b *Blobs) update(v Blob, arr []Blob) {
	for i, v2 := range arr {
		if v2.Blob == v.Blob {
			arr[i] = v
		}
	}
}

// Update given blob with the one provided.
func (b *Blobs) Update(v Blob) {
	b.update(v, b.mapg1.blobs1)
	b.update(v, b.mapg1.blobs2)
	b.update(v, b.mapg2.blobs)
	b.update(v, b.mapc.blobs1)
	b.update(v, b.mapc.blobs2)
	b.update(v, b.data.blobs)
}

// Add given blob to the list.
func (b *Blobs) Add(v Blob) {
	b.mapg1.blobs1 = append(b.mapg1.blobs1, v)
	b.mapg1.blobs2 = append(b.mapg1.blobs2, v)
	b.mapg2.blobs = append(b.mapg2.blobs, v)
	b.mapc.blobs1 = append(b.mapc.blobs1, v)
	b.mapc.blobs2 = append(b.mapc.blobs2, v)
	b.data.blobs = append(b.data.blobs, v)
}

func (b *Blobs) readMemmapC() error {
	data, err := ReadFile(memmapC)
	if err != nil {
		return err
	}
	for {
		loc := reExtC.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.mapc.pre = append(b.mapc.pre, data[:start]...)
		}
		blob, err := strconv.ParseUint(string(data[loc[2]:loc[3]]), 16, 64)
		if err != nil {
			return err
		}
		size, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 0, 64)
		if err != nil {
			return err
		}
		b.mapc.blobs1 = append(b.mapc.blobs1, Blob{
			Blob: uintptr(blob),
			Size: uintptr(size),
		})
		data = data[end:]
	}
	for {
		loc := reMapC.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.mapc.mid = append(b.mapc.mid, data[:start]...)
		}
		var blob uint64
		for i := 0; i < 3; i++ {
			v, err := strconv.ParseUint(string(data[loc[2*(i+1)]:loc[2*(i+1)+1]]), 16, 64)
			if err != nil {
				return err
			}
			if i == 0 {
				blob = v
			} else if blob != v {
				return fmt.Errorf("invalid access to 0x%X in the memmap", blob)
			}
		}
		b.mapc.blobs2 = append(b.mapc.blobs2, Blob{
			Blob: uintptr(blob),
		})
		data = data[end:]
	}
	b.mapc.post = append(b.mapc.post, data...)
	b.mapc.pre = bytes.TrimSpace(b.mapc.pre)
	b.mapc.mid = bytes.TrimSpace(b.mapc.mid)
	b.mapc.post = bytes.TrimSpace(b.mapc.post)
	return nil
}

func (b *Blobs) writeMemmapC() error {
	f, err := os.Create(Path(memmapC))
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err = f.Write(b.mapc.pre); err != nil {
		return err
	}
	bw := bufio.NewWriter(f)
	if _, err = bw.WriteString("\n\n"); err != nil {
		return err
	}
	for _, b := range b.mapc.blobs1 {
		_, err = fmt.Fprintf(bw, "extern unsigned char byte_%X[%d];\n", b.Blob, b.Size)
		if err != nil {
			return err
		}
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.mapc.mid); err != nil {
		return err
	}
	if _, err = bw.WriteString("\n"); err != nil {
		return err
	}
	for _, b := range b.mapc.blobs2 {
		_, err = fmt.Fprintf(bw, "\tcase 0x%[1]X:\n\t\tif (off+size <= sizeof(byte_%[1]X))\n\t\t\treturn &byte_%[1]X[off];\n", b.Blob, b.Size)
		if err != nil {
			return err
		}
	}
	if _, err = bw.WriteString("\t"); err != nil {
		return err
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.mapc.post); err != nil {
		return err
	}
	if _, err = f.WriteString("\n"); err != nil {
		return err
	}
	return f.Close()
}

func (b *Blobs) readMemmapGo1() error {
	data, err := ReadFile(memmapGo1)
	if err != nil {
		return err
	}
	for {
		loc := reExtC.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.mapg1.pre = append(b.mapg1.pre, data[:start]...)
		}
		blob, err := strconv.ParseUint(string(data[loc[2]:loc[3]]), 16, 64)
		if err != nil {
			return err
		}
		size, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 0, 64)
		if err != nil {
			return err
		}
		b.mapg1.blobs1 = append(b.mapg1.blobs1, Blob{
			Blob: uintptr(blob),
			Size: uintptr(size),
		})
		data = data[end:]
	}
	for {
		loc := reMapG1.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.mapg1.mid = append(b.mapg1.mid, data[:start]...)
		}
		var blob uint64
		for i := 0; i < 4; i++ {
			v, err := strconv.ParseUint(string(data[loc[2*(i+1)]:loc[2*(i+1)+1]]), 16, 64)
			if err != nil {
				return err
			}
			if i == 0 {
				blob = v
			} else if blob != v {
				return fmt.Errorf("invalid access to 0x%X in the %s", blob, memmapGo1)
			}
		}
		b.mapg1.blobs2 = append(b.mapg1.blobs2, Blob{
			Blob: uintptr(blob),
		})
		data = data[end:]
	}
	b.mapg1.post = append(b.mapg1.post, data...)
	return nil
}

func (b *Blobs) writeMemmapGo1() error {
	f, err := os.Create(Path(memmapGo1))
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err = f.Write(b.mapg1.pre); err != nil {
		return err
	}
	bw := bufio.NewWriter(f)
	for _, b := range b.mapg1.blobs1 {
		_, err = fmt.Fprintf(bw, "extern unsigned char byte_%X[%d];\n", b.Blob, b.Size)
		if err != nil {
			return err
		}
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.mapg1.mid); err != nil {
		return err
	}
	for _, b := range b.mapg1.blobs2 {
		_, err = fmt.Fprintf(bw, "\tmemmap.RegisterBlobData(0x%[1]X, \"byte_%[1]X\", unsafe.Slice((*byte)(unsafe.Pointer(&C.byte_%[1]X[0])), int(unsafe.Sizeof(C.byte_%[1]X))))\n", b.Blob, b.Size)
		if err != nil {
			return err
		}
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.mapg1.post); err != nil {
		return err
	}
	if err := f.Close(); err != nil {
		return err
	}
	if err := goFormat(memmapGo1); err != nil {
		return err
	}
	return nil
}

func (b *Blobs) readMemmapGo2() error {
	data, err := ReadFile(memmapGo2)
	if err != nil {
		return err
	}
	for {
		loc := reMapG2.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		end := loc[1]
		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.mapg2.pre = append(b.mapg2.pre, data[:start]...)
		}
		blob, err := strconv.ParseUint(string(data[loc[2]:loc[3]]), 16, 64)
		if err != nil {
			return err
		}
		blob2, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 16, 64)
		if err != nil {
			return err
		}
		if blob != blob2 {
			return fmt.Errorf("invalid blob in %s", memmapGo2)
		}
		size, err := strconv.ParseUint(string(data[loc[6]:loc[7]]), 0, 64)
		if err != nil {
			return err
		}
		b.mapg2.blobs = append(b.mapg2.blobs, Blob{
			Blob: uintptr(blob),
			Size: uintptr(size),
		})
		data = data[end:]
	}
	b.mapg2.post = append(b.mapg2.post, data...)
	return nil
}

func (b *Blobs) writeMemmapGo2() error {
	f, err := os.Create(Path(memmapGo2))
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err = f.Write(b.mapg2.pre); err != nil {
		return err
	}
	bw := bufio.NewWriter(f)
	for _, b := range b.mapg2.blobs {
		_, err = fmt.Fprintf(bw, "\tmemmap.RegisterBlob(0x%[1]X, \"byte_%[1]X\", %[2]d)\n", b.Blob, b.Size)
		if err != nil {
			return err
		}
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.mapg2.post); err != nil {
		return err
	}
	if err := f.Close(); err != nil {
		return err
	}
	if err := goFormat(memmapGo2); err != nil {
		return err
	}
	return nil
}

func (b *Blobs) readData() error {
	data, err := ReadFile(dataC)
	if err != nil {
		return err
	}
	for {
		loc := reDataC.FindSubmatchIndex(data)
		if len(loc) == 0 {
			break
		}
		start := loc[0]
		i := loc[1]

		if len(bytes.TrimSpace(data[:start])) > 0 {
			b.data.pre = append(b.data.pre, data[:start]...)
		}

		blob, err := strconv.ParseUint(string(data[loc[2]:loc[3]]), 16, 64)
		if err != nil {
			return err
		}
		size, err := strconv.ParseUint(string(data[loc[4]:loc[5]]), 0, 64)
		if err != nil {
			return err
		}

		lbrace := bytes.IndexByte(data[i:], '{')
		if lbrace < 0 {
			break
		}
		lbrace += i

		rbrace := bytes.IndexByte(data[lbrace+1:], '}')
		if rbrace < 0 {
			break
		}
		rbrace += lbrace + 1

		end := bytes.IndexByte(data[rbrace+1:], ';')
		if end < 0 {
			break
		}
		end += rbrace + 2

		bdata, err := b.parseBytes(data[lbrace+1:rbrace], int(size))
		if err != nil {
			return err
		}
		b.data.blobs = append(b.data.blobs, Blob{
			Blob: uintptr(blob),
			Size: uintptr(size),
			Data: bdata,
		})
		data = data[end:]
	}
	b.data.post = append(b.data.post, data...)
	b.data.pre = bytes.TrimSpace(b.data.pre)
	b.data.post = bytes.TrimSpace(b.data.post)
	return nil
}

func (b *Blobs) writeData() error {
	f, err := os.Create(Path(dataC))
	if err != nil {
		return err
	}
	defer f.Close()

	if _, err = f.Write(b.data.pre); err != nil {
		return err
	}
	bw := bufio.NewWriter(f)
	if err = bw.WriteByte('\n'); err != nil {
		return err
	}
	for _, v := range b.data.blobs {
		_, err = fmt.Fprintf(bw, "\nunsigned char byte_%X[%d] = {", v.Blob, v.Size)
		if err != nil {
			return err
		}
		if len(v.Data) == 0 {
			_, err = bw.WriteString("0};\n")
			if err != nil {
				return err
			}
			continue
		}
		for i, b := range v.Data {
			if i%20 == 0 {
				if _, err = bw.WriteString("\n\t"); err != nil {
					return err
				}
			} else {
				if err = bw.WriteByte(' '); err != nil {
					return err
				}
			}
			_, err = fmt.Fprintf(bw, "0x%02x", b)
			if err != nil {
				return err
			}
			if i+1 < len(v.Data) {
				if err = bw.WriteByte(','); err != nil {
					return err
				}
			}
		}
		_, err = bw.WriteString("\n};\n")
		if err != nil {
			return err
		}
	}
	if err = bw.WriteByte('\n'); err != nil {
		return err
	}
	if err = bw.Flush(); err != nil {
		return err
	}
	if _, err = f.Write(b.data.post); err != nil {
		return err
	}
	return f.Close()
}

func (b *Blobs) parseBytes(p []byte, size int) ([]byte, error) {
	out := make([]byte, 0, size)
	for len(p) > 0 {
		i := bytes.IndexByte(p, ',')
		ni := i + 1
		if i < 0 {
			i = len(p)
			ni = len(p)
		}
		w := bytes.TrimSpace(p[:i])
		p = p[ni:]
		if n := len(w); n == 0 {
			break
		} else if w[n-1] == 'u' {
			w = w[:n-1]
		}
		v, err := strconv.ParseUint(string(w), 0, 8)
		if err != nil {
			return out, err
		}
		out = append(out, byte(v))
	}
	if len(out) == 0 || (len(out) == 1 && out[0] == 0) {
		out = nil // blob = {0}
	}
	return out, nil
}

// Write the changes back to files.
func (b *Blobs) Write() error {
	if err := b.writeMemmapGo1(); err != nil {
		return err
	}
	if err := b.writeMemmapGo2(); err != nil {
		return err
	}
	if err := b.writeMemmapC(); err != nil {
		return err
	}
	if err := b.writeData(); err != nil {
		return err
	}
	return nil
}
