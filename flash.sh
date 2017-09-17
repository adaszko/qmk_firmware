#!/bin/bash


main () {
    local volume="/Volumes/TADA68  "
    make tada68-default-bin
    if [[ ! -d $volume ]]; then
        echo "$volume: not a directory"
        return 1
    fi
    rm -rf "$volume/.fseventsd" "$volume/FLASH.BIN"
    cp tada68_default.bin "$volume/"
}


main "$@"
