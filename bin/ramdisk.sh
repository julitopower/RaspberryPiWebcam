# This script creates a ramdisk in /mnt/ramdisk/webcam
# if the location does not exist

RAMDISK_BASE="/mnt/ramdisk"
RAMDISK_FOLDER="webcam"
MOUNT_POINT="$RAMDISK_BASE/$RAMDISK_FOLDER"
SIZE="5m"

if [ ! -d "$MOUNT_POINT" ]; then
    mkdir -p $MOUNT_POINT
fi

mount -t tmpfs -o size=$SIZE tmpfs $MOUNT_POINT;
