# Get the interface name using "ifconfig", e.g., wlan0, and
# update the script.
# For help, see "man iwconfig".
# put the device down
ifconfig eth0 down
# none cell, no access point
iwconfig eth0 mode Ad-hoc
# cell name
iwconfig eth0 essid MyCell
# channel
iwconfig eth0 channel 3
# data rate
# iwconfig eth0 rate 11MB
# identity of ad hoc network cell
iwconfig eth0 ap 00:00:00:00:00:01
# put the device up
ifconfig eth0 up
iwconfig eth0
