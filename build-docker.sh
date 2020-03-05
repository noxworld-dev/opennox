#!/bin/bash
DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
DOCKERFILES_DIR="${DIR}/docker"

set -e

__setup_dir_structure() {
	if [ -d "${DIR}/build/linux" ]
	then
		rm -rf "${DIR}/build/linux"
	fi

	if [ -d "${DIR}/build/web" ]
	then
		rm -rf "${DIR}/build/web"
	fi

	mkdir -p ${DIR}/build
	mkdir -p ${DIR}/build/linux
	mkdir -p ${DIR}/build/web
	mkdir -p ${DIR}/build/ccache
	mkdir -p ${DIR}/build/emscripten_cache

	return 0
}

__build_docker_images() {
	echo "Building builder images..."
	docker build -t nox:base_build_image -f "${DOCKERFILES_DIR}/Dockerfile_base" "${DOCKERFILES_DIR}"
	if [ $? -ne 0 ]
	then
		>&2 echo "ERROR: Failed to build base build image"
		return 2
	fi

	if [ "${BUILD_LINUX}" == "YES" ]
	then
		docker build -t nox:linux -f "${DOCKERFILES_DIR}/Dockerfile_linux" "${DOCKERFILES_DIR}"
		if [ $? -ne 0 ]
		then
			>&2 echo "ERROR: Failed to build linux build image"
			return 3
		fi
	fi

	if [ "${BUILD_WASM}" == "YES" ]
	then
		docker build -t nox:wasm -f "${DOCKERFILES_DIR}/Dockerfile_wasm" "${DOCKERFILES_DIR}"
		if [ $? -ne 0 ]
		then
			>&2 echo "ERROR: Failed to build wasm build image"
			return 4
		fi
	fi

	return 0
}

__build_app_linux() {
	echo "Building project (target=linux)..."
	docker run --rm --user $(id -u):$(id -g) \
		-v ${DIR}/build/ccache:/home/runner/.ccache \
		-v ${DIR}/src:/home/runner/src:ro \
		-v ${DIR}/build/linux:/home/runner/bin \
		--network="none" \
		nox:linux

	if [ $? -ne 0 ]
	then
		>&2 echo "ERROR: Failed to build for Linux"
		return 2
	fi

	return 0
}

__build_app_wasm() {
	echo "Building project (target=wasm)..."
	docker run --rm --user $(id -u):$(id -g) \
		-v ${DIR}/build/ccache:/home/runner/.ccache \
		-v ${DIR}/build/emscripten_cache:/home/runner/.emscripten_cache \
		-v ${DIR}/src:/home/runner/src:ro \
		-v ${DIR}/build/web:/home/runner/bin \
		nox:wasm

	if [ $? -ne 0 ]
	then
		>&2 echo "ERROR: Failed to build for WASM"
		return 2
	fi

	cp ${DIR}/src/ws-server/static/* ${DIR}/build/web/
	return $?
}

BUILD_LINUX=""
BUILD_WASM=""
SEEN_TARGET=""

for i in "$@"
do
case $i in
    -t=*|--target=*)
    __tmp="${i#*=}"
    shift # past argument=value
    SEEN_TARGET="YES"
    if [ "${__tmp}" == "linux" ]
	then
		BUILD_LINUX="YES"
	elif [ "${__tmp}" == "wasm" ]
	then
		BUILD_WASM="YES"
	fi
    ;;
    *)
          # unknown option
    ;;
esac
done
# Apply defaults
if [ "z${SEEN_TARGET}" == "z" ]
then
	BUILD_LINUX="YES"
	BUILD_WASM="YES"
fi

__setup_dir_structure
__build_docker_images
if [ "${BUILD_LINUX}" == "YES" ]
then
	__build_app_linux
fi
if [ "${BUILD_WASM}" == "YES" ]
then
	__build_app_wasm
fi
echo "done!"
