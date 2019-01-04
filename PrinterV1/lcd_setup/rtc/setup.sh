#setup ds3231 hwclock!
echo "setup ds3231 hwclock!"
sleep 1
sudo apt-get -y remove fake-hwclock
sudo update-rc.d -f fake-hwclock remove
# update /lib/udev/hwclock-set
sudo mv /lib/udev/hwclock-set /lib/udev/hwclock-set.bak
sudo cp ./hwclock-set /lib/udev/hwclock-set
#Sync time from Pi to RTC
sudo hwclock -D -r
#step1 set date : sudo date 061914482017.30
#step2 sudo hwclock -w
#step3 sudo hwclock -r

