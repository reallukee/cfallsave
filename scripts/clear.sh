#!/bin/bash

folders=(
    "bin"
    "obj"
    "windows/.vs"
    "windows/bin"
    "windows/obj"
    "osx/bin"
    "osx/obj"
)

for folder in "${folders[@]}"; do
    if [ -d "../$folder" ]; then
        rm -rf "../$folder"
    fi
done
