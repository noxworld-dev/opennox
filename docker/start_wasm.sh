#!/bin/sh
set -xe

cd ~/emsdk
emcmake cmake ~/src
emmake make
cp out* ~/bin/
