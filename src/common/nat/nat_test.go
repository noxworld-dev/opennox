package nat

import (
	"context"
	"testing"
	"time"

	"nox/v1/common"
)

func TestNAT(t *testing.T) {
	start := time.Now()
	stop, err := Map(context.Background(), []Port{{
		Proto: "udp",
		Port:  common.GamePort,
		Desc:  "Nox game port",
	}})
	t.Log("mapped in", time.Since(start))
	if err != nil {
		t.Fatal(err)
	}
	defer stop()
}
