#!/bin/bash
set -e

TMP_DIR=/tmp/noxg-release
NOXG_LINUX=~/Downloads/noxg-linux.zip
NOXG_WIN=~/Downloads/noxg-win.zip
NOX_WIN=~/Downloads/nox-win.zip
NOX_SRC="$(pwd)"

rm -rf "$TMP_DIR"
mkdir -p "$TMP_DIR"
cd "$TMP_DIR"

# ==== [ Windows ] ====

mkdir tmp-win
unzip "$NOX_WIN" -d ./tmp-win/

mkdir tmp-win-2
unzip "$NOXG_WIN" -d ./tmp-win-2/

mkdir tmp-win-3
unzip ./tmp-win-2/nox-win.zip -d ./tmp-win-3/
rm -rf ./tmp-win-2/

mkdir ./noxg-win
cp ./tmp-win/*.dll ./noxg-win/
cp ./tmp-win-3/tmp/*.exe ./noxg-win/
cp $NOX_SRC/CHANGELOG.md ./noxg-win/
mkdir ./noxg-win/docs
cp $NOX_SRC/docs/game-*.md ./noxg-win/docs/
cp $NOX_SRC/docs/mod-*.md ./noxg-win/docs/

rm -rf ./tmp-win/
rm -rf ./tmp-win-3/

cd ./noxg-win
zip -9 -r ../noxg-win.zip ./*
cd ..

rm -rf ./noxg-win

cp ./noxg-win.zip "$NOX_SRC/"

# ==== [ Linux ] ====

mkdir tmp-linux
unzip "$NOXG_LINUX" -d ./tmp-linux/

mkdir tmp-linux-2
tar -xvzf ./tmp-linux/nox-linux.tar.gz -C ./tmp-linux-2/
rm -rf ./tmp-linux/

mkdir ./noxg-linux
cp ./tmp-linux-2/tmp/* ./noxg-linux/
cp $NOX_SRC/CHANGELOG.md ./noxg-linux/
mkdir ./noxg-linux/docs
cp $NOX_SRC/docs/game-*.md ./noxg-linux/docs/
cp $NOX_SRC/docs/mod-*.md ./noxg-linux/docs/

rm -rf ./tmp-linux-2/

cd ./noxg-linux
tar -czf ../noxg-linux.tar.gz ./*
cd ..

rm -rf ./noxg-linux

cp ./noxg-linux.tar.gz "$NOX_SRC/"
