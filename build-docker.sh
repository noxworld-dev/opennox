#!/bin/bash
rm -rf build;
set -e
mkdir -p build/linux
mkdir -p build/web
docker build -t nox:linux -f Dockerfile_linux .
docker build -t nox:wasm -f Dockerfile_wasm .
echo "build complete, copying files..."
docker run --rm --user $(id -u):$(id -g) -v $(pwd)/build/linux:/ext --entrypoint bash nox:linux -c 'cp /src/out* /ext/'
docker run --rm --user $(id -u):$(id -g) -v $(pwd)/build/web:/ext --entrypoint bash nox:wasm -c 'cp /src/out* /ext/'
cp ./src/ws-server/static/* ./build/web/
echo "done!"