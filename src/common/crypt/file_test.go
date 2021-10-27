package crypt

import (
	"io"
	"io/ioutil"
	"os"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestFileRead(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c\x49\x28\x27\x6d\x9a\x62\x8e\x94\x95\x36\x9f\xa2\x0d\xd0\x04\xee"
		decoded = "ROLF\x01\x00\x00\x00\x03\x4d\x75\x64\x3e\x20\x03\x00\x08\x00\x00\x00\x00\x00\x00\x00"
	)
	f, err := os.CreateTemp("", "crypt-file-")
	if err != nil {
		t.Fatal(err)
	}
	defer func() {
		f.Close()
		os.Remove(f.Name())
	}()
	_, err = f.WriteString(encoded)
	require.NoError(t, err)
	_, err = f.Seek(0, io.SeekStart)
	require.NoError(t, err)

	r, err := NewFile(f, key)
	require.NoError(t, err)
	out, err := ioutil.ReadAll(r)
	require.NoError(t, err)
	require.Equal(t, decoded, string(out))

	for i := 1; i < len(encoded); i++ {
		_, err = f.Seek(0, io.SeekStart)
		require.NoError(t, err)
		r, err = NewFile(f, key)
		require.NoError(t, err)
		_, err = r.Seek(int64(i), io.SeekCurrent)
		require.NoError(t, err)
		out, err = ioutil.ReadAll(r)
		require.NoError(t, err)
		require.Equal(t, decoded[i:], string(out))
	}
}

func TestFileWrite(t *testing.T) {
	const (
		key     = ThingBin
		encoded = "\x2c\xc3\x70\x31\x5e\xda\x12\x3c\x49\x28\x27\x6d\x9a\x62\x8e\x94\x95\x36\x9f\xa2\x0d\xd0\x04\xee"
		decoded = "ROLF\x01\x00\x00\x00\x03\x4d\x75\x64\x3e\x20\x03\x00\x08\x00\x00\x00\x00\x00\x00\x00"
	)
	f, err := os.CreateTemp("", "crypt-file-")
	if err != nil {
		t.Fatal(err)
	}
	defer func() {
		f.Close()
		os.Remove(f.Name())
	}()

	w, err := NewFile(f, key)
	require.NoError(t, err)
	_, err = w.Write([]byte(decoded))
	require.NoError(t, err)
	err = w.Close()
	require.NoError(t, err)
	_, err = f.Seek(0, io.SeekStart)
	require.NoError(t, err)
	buf, err := io.ReadAll(f)
	require.NoError(t, err)
	require.Equal(t, encoded, string(buf))
}

func TestFileWriteSeek(t *testing.T) {
	const (
		key = ThingBin
	)
	f, err := os.CreateTemp("", "crypt-file-")
	if err != nil {
		t.Fatal(err)
	}
	defer func() {
		f.Close()
		os.Remove(f.Name())
	}()

	cf, err := NewFile(f, key)
	require.NoError(t, err)

	assertData := func(s string) {
		_, err := cf.Seek(0, io.SeekStart)
		require.NoError(t, err)
		data, err := io.ReadAll(cf)
		require.NoError(t, err)
		require.Equal(t, s, string(data))
	}

	_, err = cf.WriteString("1234")
	require.NoError(t, err)
	err = cf.Flush()
	require.NoError(t, err)

	assertData("1234\x00\x00\x00\x00")

	_, err = cf.Seek(4, io.SeekStart)
	require.NoError(t, err)
	_, err = cf.WriteString("56")
	require.NoError(t, err)
	err = cf.Flush()
	require.NoError(t, err)

	assertData("123456\x00\x00")

	_, err = cf.Seek(6, io.SeekStart)
	require.NoError(t, err)
	_, err = cf.WriteString("7890")
	require.NoError(t, err)
	err = cf.Flush()
	require.NoError(t, err)

	assertData("1234567890\x00\x00\x00\x00\x00\x00")

	_, err = cf.Seek(6, io.SeekStart)
	require.NoError(t, err)
	var buf [4]byte
	_, err = io.ReadFull(cf, buf[:])
	require.NoError(t, err)
	require.Equal(t, "7890", string(buf[:]))
	_, err = cf.WriteString("abc")
	require.NoError(t, err)
	err = cf.Flush()
	require.NoError(t, err)

	assertData("1234567890abc\x00\x00\x00")

	_, err = cf.Seek(2, io.SeekStart)
	require.NoError(t, err)
	_, err = cf.WriteString("def")
	require.NoError(t, err)
	_, err = io.ReadFull(cf, buf[:])
	require.NoError(t, err)
	require.Equal(t, "6789", string(buf[:]))
	err = cf.Flush()
	require.NoError(t, err)

	assertData("12def67890abc\x00\x00\x00")

	_, err = cf.Seek(4, io.SeekStart)
	require.NoError(t, err)
	_, err = io.ReadFull(cf, buf[:])
	require.NoError(t, err)
	require.Equal(t, "f678", string(buf[:]))
	_, err = cf.WriteString("ghij")
	require.NoError(t, err)
	err = cf.Flush()
	require.NoError(t, err)

	assertData("12def678ghijc\x00\x00\x00")

	_, err = cf.Seek(4, io.SeekStart)
	_, err = cf.WriteString("klmn")
	require.NoError(t, err)
	require.NoError(t, err)
	_, err = io.ReadFull(cf, buf[:])
	require.NoError(t, err)
	require.Equal(t, "ghij", string(buf[:]))
	err = cf.Flush()
	require.NoError(t, err)

	assertData("12deklmnghijc\x00\x00\x00")
}
