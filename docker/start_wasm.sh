#! /bin/sh
set -xe

cd ~/emsdk
emconfigure cmake ~/src
emmake make
cp out* ~/bin/
