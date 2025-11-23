#!/bin/bash

folders=(
    "bin"
    "obj"
    "windows/.vs"
    "windows/bin"
    "windows/obj"
    "macos/bin"
    "macos/obj"
)

for folder in "${folders[@]}"; do
    if [ -d "../$folder" ]; then
        rm -rf "../$folder"
    fi
done
