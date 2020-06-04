#! /bin/sh
set -xe

NPROC=$( nproc --ignore=2 )
echo "Will build with ${NPROC} jobs"

cd ~/build
cmake –G"Unix Makefiles" ~/src

cd ~/src
cmake --build ~/build --target out --parallel ${NPROC}

cp ~/build/out* ~/bin/
