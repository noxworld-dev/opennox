package nat

import (
	"context"
	"testing"
	"time"
)

func TestNAT(t *testing.T) {
	start := time.Now()
	stop, err := Map(context.Background(), []Port{{
		Proto: "udp",
		Port:  18590,
		Desc:  "Nox game port",
	}})
	t.Log("mapped in", time.Since(start))
	if err != nil {
		t.Fatal(err)
	}
	defer stop()
}
