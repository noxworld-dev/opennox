package version

import (
	"context"
	"encoding/json"
	"errors"
	"fmt"
	"net/http"
	"net/url"
)

const (
	githubBaseURL   = "https://ghcr.io"
	githubOrg       = "noxworld-dev"
	githubRepo      = "opennox-docker"
	githubRepoFull  = githubOrg + "/" + githubRepo
	githubImage     = "opennox"
	githubImageFull = githubOrg + "/" + githubImage
)

// latestGithub checks the latest Docker image version on GitHub Container Registry, where we host OpenNox server images.
func latestGithub(ctx context.Context) (string, error) {
	token, err := getGithubToken(ctx)
	if err != nil {
		return "", fmt.Errorf("github: %w", err)
	}
	vers, err := getGithubLatestImage(ctx, token)
	if err != nil {
		return "", fmt.Errorf("github: %w", err)
	}
	return vers, nil
}

// getGithubToken returns a GitHub token suitable for checking GitHub Container Registry anonymously.
func getGithubToken(ctx context.Context) (string, error) {
	qu := make(url.Values)
	qu.Set("scope", "repository:"+githubImageFull+":pull")
	addr := githubBaseURL + "/token?" + qu.Encode()
	Log.Println("GET", addr)
	req, err := http.NewRequestWithContext(ctx, "GET", addr, nil)
	if err != nil {
		return "", err
	}
	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		return "", err
	}
	defer resp.Body.Close()
	if resp.StatusCode/100 != 2 {
		return "", fmt.Errorf("status: %s", resp.Status)
	}
	var token struct {
		Token string `json:"token"`
	}
	if err := json.NewDecoder(resp.Body).Decode(&token); err != nil {
		return "", err
	}
	if token.Token == "" {
		return "", errors.New("cannot get Github token")
	}
	return token.Token, nil
}

// getGithubLatestImage returns the latest version (tag) on GitHub Container Registry, where we host OpenNox server images.
func getGithubLatestImage(ctx context.Context, token string) (string, error) {
	addr := githubBaseURL + "/v2/" + githubImageFull + "/tags/list"
	Log.Println("GET", addr)
	req, err := http.NewRequestWithContext(ctx, "GET", addr, nil)
	if err != nil {
		return "", err
	}
	req.Header.Set("Authorization", "Bearer "+token)
	req.Header.Set("Accept", "application/vnd.oci.image.manifest.v1+json")
	resp, err := http.DefaultClient.Do(req)
	if err != nil {
		return "", err
	}
	defer resp.Body.Close()
	if resp.StatusCode/100 != 2 {
		return "", fmt.Errorf("status: %s", resp.Status)
	}
	var tags struct {
		Tags []string `json:"tags"`
	}
	if err := json.NewDecoder(resp.Body).Decode(&tags); err != nil {
		return "", err
	}
	if len(tags.Tags) == 0 {
		return "", errors.New("cannot get Github tags")
	}
	return semverLatestFromList(tags.Tags), nil
}
