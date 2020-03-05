#! /bin/sh
set -xe

cd ~/build
cmake ~/src
make
cp out* ~/bin/
