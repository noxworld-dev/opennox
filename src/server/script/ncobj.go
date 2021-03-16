package script

import (
	"encoding/binary"
	"errors"
	"fmt"
	"io"
	"strconv"
	"strings"
)

const NCobjName = "nc.obj"

func (r *Runtime) ReadNCobj(f io.Reader) error {
	r.Reset()

	readInt := func() (int, error) {
		var b [4]byte
		_, err := io.ReadFull(f, b[:])
		if err != nil {
			return 0, err
		}
		v := int32(binary.LittleEndian.Uint32(b[:]))
		return int(v), nil
	}
	readString := func(sz int) (string, error) {
		buf := make([]byte, sz)
		_, err := io.ReadFull(f, buf)
		if err != nil {
			return "", err
		}
		return string(buf), nil
	}
	expect := func(exp string) error {
		got, err := readString(len(exp))
		if err != nil {
			return err
		}
		if exp != got {
			return fmt.Errorf("unexpected string: %q", got)
		}
		return nil
	}

	if err := expect("SCRIPT03"); err != nil {
		return err
	}
	if err := expect("STRG"); err != nil {
		return err
	}
	cnt, err := readInt()
	if err != nil {
		return err
	} else if cnt < 0 {
		return errors.New("negative strings count")
	}
	// TODO: xxx = cnt
	for i := 0; i < cnt; i++ {
		n, err := readInt()
		if err != nil {
			return err
		}
		s, err := readString(n)
		if err != nil {
			return err
		}
		r.AddString(s)
	}
	if err := expect("CODE"); err != nil {
		return err
	}
	scnt, err := readInt()
	if err != nil {
		return err
	} else if scnt < 0 {
		return errors.New("negative func count")
	}
	r.scripts = make([]Script, 0, scnt)
	for i := 0; i < scnt; i++ {
		if err := expect("FUNC"); err != nil {
			return err
		}
		sc := Script{r: r}

		n, err := readInt()
		if err != nil {
			return err
		}
		s, err := readString(n)
		if err != nil {
			return err
		}
		sub := strings.SplitN(s, "%", 4)

		sc.name = s
		if len(sub) == 4 {
			// TODO: check; looks like debug info
			sc.f36 = "%" + sub[1]
			v, _ := strconv.Atoi(sub[2])
			sc.f40 = v
			v, _ = strconv.Atoi(sub[3])
			sc.f44 = v
		}
		n, err = readInt()
		if err != nil {
			return err
		}
		sc.stackSize = n

		n, err = readInt()
		if err != nil {
			return err
		}
		sc.size28 = n

		if err := expect("SYMB"); err != nil {
			return err
		}
		cntY, err := readInt()
		if err != nil {
			return err
		}
		if i == 0 {
			cntY++
		}
		sc.field12 = cntY

		_, err = readInt()
		if err != nil {
			return err
		}
		if cntY > 0 {
			sc.field20 = make([]int32, cntY)
			sc.field24 = make([]int32, cntY)
		}
		j1 := 0
		if i == 0 {
			j1 = 1
			sc.field20[0] = 0
			sc.field24[0] = 0
		}
		sum := 0
		for j := j1; j < cntY; j++ {
			v, err := readInt()
			if err != nil {
				return err
			}
			sc.field20[j] = int32(v)
			sc.field24[j] = int32(sum)
			sum += v
		}
		sc.field16 = sum
		if sum != 0 {
			sc.field28 = make([]int32, sum)
		}
		if err := expect("DATA"); err != nil {
			return err
		}
		n, err = readInt()
		if err != nil {
			return err
		}
		sc.code = make([]byte, n)
		_, err = io.ReadFull(f, sc.code)
		if err != nil {
			return err
		}
		r.scripts = append(r.scripts, sc)
	}
	if err := expect("DONE"); err != nil {
		return err
	}
	return nil
}
