#!/usr/bin/env bash

#
# google docet - jump within the directory which contains this script
#

SOURCE="${BASH_SOURCE[0]}"

while [ -h "$SOURCE" ]; do
    DIR="$(cd -P "$(dirname "$SOURCE")" && pwd)"
    SOURCE="$(readlink "$SOURCE")"
    [[ $SOURCE != /* ]] && SOURCE="$DIR/$SOURCE"
done


DIR="$(cd -P "$(dirname "$SOURCE")" && pwd)"


cd "$DIR"
git submodule update --init # --recursive

rm -rf "$DIR"/deps/googletest/build
mkdir "$DIR"/deps/googletest/build
cd "$DIR"/deps/googletest/build
cmake .. && make -j4


cd "$DIR"
