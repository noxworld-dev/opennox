#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"

rm -rf ${DIR}/build/linux ${DIR}/build/web

set -e

mkdir -p ${DIR}/build
mkdir -p ${DIR}/build/linux
mkdir -p ${DIR}/build/web
mkdir -p ${DIR}/build/ccache
mkdir -p ${DIR}/build/emscripten_cache

echo "Building builder images..."
cd ${DIR}/docker
docker build -t nox:base_build_image -f Dockerfile_base .
docker build -t nox:linux -f Dockerfile_linux .
docker build -t nox:wasm -f Dockerfile_wasm .

echo "Building project (target=linux)..."
docker run --rm --user $(id -u):$(id -g) \
	-v ${DIR}/build/ccache:/home/runner/.ccache \
	-v ${DIR}/src:/home/runner/src:ro \
	-v ${DIR}/build/linux:/home/runner/bin \
	--network="none" \
	nox:linux

echo "Building project (target=wasm)..."
docker run --rm --user $(id -u):$(id -g) \
	-v ${DIR}/build/ccache:/home/runner/.ccache \
	-v ${DIR}/build/emscripten_cache:/home/runner/.emscripten_cache \
	-v ${DIR}/src:/home/runner/src:ro \
	-v ${DIR}/build/web:/home/runner/bin \
	nox:wasm
cp ${DIR}/src/ws-server/static/* ${DIR}/build/web/

echo "done!"
