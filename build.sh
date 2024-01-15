#! /bin/sh

set -xe

if [ "$1" == "verify" ]; then
	echo verifying code ...
	arduino-cli compile --fqbn esp32:esp32:esp32 packages/icarus/
elif [ "$1" == "upload" ]; then
	echo uploading code ...
else
	echo "Invalid argument. Please use 'verify' or 'upload'."
    exit 1
fi