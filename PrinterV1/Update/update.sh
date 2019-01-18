#!/bin/bash
sudo killall WINSUN
sudo killall PicShow
sudo cp /home/pi/Nepho3DConfig/Update/WINSUN
avrdude -c avrdude.conf -v -p atmega328p -c arduino -P /dev/ttyUSB0 -b 115200 -D -U flash:w:/home/pi/Nepho3DConfig/Update/firmware.hex:i  
if [ $? -ne 1 ] 
then
	echo "success"
else
	echo "failed"
fi
exit
#sudo reboot
