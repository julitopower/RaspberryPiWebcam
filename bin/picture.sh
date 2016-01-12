OUTPUT_PATH="/mnt/ramdisk/webcam"
WIDTH=800
HEIGHT=600

# Take a picture and make sure we only keep 3 pictures
while true; do
    suffix=`date "+%m%d%H%M%Y%S"`
#    raspistill -ex verylong -o "$OUTPUT_PATH/pic_$suffix.jpg"    
    raspistill -ex verylong -w $WIDTH -h $HEIGHT -o "$OUTPUT_PATH/pic_$suffix.jpg"
    ls -d -1 -t "$OUTPUT_PATH/"* | sed -e '1,3d' | xargs -d '\n' rm 2> /dev/null
done
