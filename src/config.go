package main

import (
	"os"
	"path/filepath"

	"github.com/spf13/viper"

	"nox/v1/common/log"
)

func init() {
	wd, err := os.Getwd()
	if err != nil {
		wd = "."
	}
	configPath = filepath.Join(wd, configName+"."+configExt)
	viper.SetConfigName(configName)
	viper.SetConfigType(configExt)
	viper.AddConfigPath(wd)
	viper.AddConfigPath(filepath.Dir(os.Args[0]))
}

const (
	configName        = "opennox"
	configExt         = "yml"
	configNoxDataPath = "game.data"
)

var (
	configLog      = log.New("config")
	configPath     string
	configDirty    bool
	configReadOnly = isDedicatedServer
)

func writeConfig() error {
	if configReadOnly {
		return nil
	}
	configLog.Printf("writing to %q", configPath)
	if err := viper.WriteConfigAs(configPath); err != nil {
		configLog.Printf("cannot save file: %v", err)
		return err
	}
	return nil
}

func maybeWriteConfig() {
	if !configDirty {
		return
	}
	_ = writeConfig()
}

func writeConfigLater() {
	configDirty = true
}

func readConfig(path string) error {
	if path != "" {
		viper.SetConfigFile(path)
		configPath = path
	}
	err := viper.ReadInConfig()
	if err == nil {
		configPath = viper.ConfigFileUsed()
		configDirty = false
		configLog.Printf("using file: %q", configPath)
		return nil
	}
	if _, ok := err.(viper.ConfigFileNotFoundError); ok {
		writeConfigLater()
		configLog.Println("file not found, using defaults")
		return nil
	}
	// There's a weird behavior in viper that it may try to read config file without extension.
	// It's a problem for us because we have "opennox" binary on Linux, so viper will read the binary itself and fail.
	// So we check this case and ignore it as if the config was not found.
	if filepath.Base(viper.ConfigFileUsed()) == configName {
		writeConfigLater()
		configLog.Println("file not found, using defaults")
		return nil
	}
	return err // error parsing config
}
