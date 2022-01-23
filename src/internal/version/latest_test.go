package version

import (
	"context"
	"testing"

	"github.com/stretchr/testify/require"
)

func TestLatestGithub(t *testing.T) {
	ctx := context.Background()
	token, err := getGithubToken(ctx)
	require.NoError(t, err)
	t.Log(token)
	vers, err := getGithubLatestImage(ctx, token)
	require.NoError(t, err)
	t.Log("latest:", vers)
}
