#!/usr/bin/env sh

conan install .. -s compiler=clang -s compiler.version=10 -s compiler.libcxx=libstdc++ --build=missing
