#!/bin/bash
set -e

TMP_DIR=/tmp/opennox-release
OPENNOX_LINUX=~/Downloads/opennox-linux.zip
OPENNOX_WIN=~/Downloads/opennox-win.zip
NOX_WIN=~/Downloads/nox-win.zip
NOX_SRC="$(pwd)"

rm -rf "$TMP_DIR"
mkdir -p "$TMP_DIR"
cd "$TMP_DIR"

# ==== [ Windows ] ====

mkdir tmp-win
unzip "$NOX_WIN" -d ./tmp-win/

mkdir tmp-win-2
unzip "$OPENNOX_WIN" -d ./tmp-win-2/

mkdir tmp-win-3
unzip ./tmp-win-2/opennox-win.zip -d ./tmp-win-3/
rm -rf ./tmp-win-2/

mkdir ./opennox-win
cp ./tmp-win/*.dll ./opennox-win/
cp ./tmp-win-3/tmp/*.exe ./opennox-win/
cp $NOX_SRC/CHANGELOG.md ./opennox-win/
mkdir ./opennox-win/docs
cp $NOX_SRC/docs/game-*.md ./opennox-win/docs/
cp $NOX_SRC/docs/mod-*.md ./opennox-win/docs/
cp $NOX_SRC/docs/maps-*.md ./opennox-win/docs/
cp $NOX_SRC/docs/*-sample.yml ./opennox-win/docs/

rm -rf ./tmp-win/
rm -rf ./tmp-win-3/

cd ./opennox-win
zip -9 -r ../opennox-win.zip ./*
cd ..

rm -rf ./opennox-win

cp ./opennox-win.zip "$NOX_SRC/"

# ==== [ Linux ] ====

mkdir tmp-linux
unzip "$OPENNOX_LINUX" -d ./tmp-linux/

mkdir tmp-linux-2
tar -xvzf ./tmp-linux/opennox-linux.tar.gz -C ./tmp-linux-2/
rm -rf ./tmp-linux/

mkdir ./opennox-linux
cp ./tmp-linux-2/tmp/* ./opennox-linux/
cp $NOX_SRC/CHANGELOG.md ./opennox-linux/
mkdir ./opennox-linux/docs
cp $NOX_SRC/docs/game-*.md ./opennox-linux/docs/
cp $NOX_SRC/docs/mod-*.md ./opennox-linux/docs/
cp $NOX_SRC/docs/maps-*.md ./opennox-linux/docs/
cp $NOX_SRC/docs/*-sample.yml ./opennox-linux/docs/

rm -rf ./tmp-linux-2/

cd ./opennox-linux
tar -czf ../opennox-linux.tar.gz ./*
cd ..

rm -rf ./opennox-linux

cp ./opennox-linux.tar.gz "$NOX_SRC/"
