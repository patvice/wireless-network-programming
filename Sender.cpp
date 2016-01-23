// File: Sender.cpp
// Author: Michel Barbeau
// Version: January 16, 2016

#include "Sender.h"
#include "WLAN.h"
#include "label.h"

using namespace std;

int main(int argc, char ** argv) {
   // create a sender
   Sender* aSender=new Sender();
   // create a wireless network abstraction
   WLAN* aWLAN=new WLAN(LABEL);
   // initialize
   aWLAN->init();
   // send a frame
   // char a[]="ff:ff:ff:ff:ff:ff"; // broadcast address
   char address[]="1c:bd:b9:7e:b6:5a"; // unicast address
   char message[]="This is a test frame"; // data

   // Build Address
   WLAN::WLANAddr daddr;
   aWLAN->buildHeader(address, &daddr);

   char buff[aWLAN->getAddressLength()+strlen(message)];

   // memmove probably need to be changed somehow
   memmove(buff, &hdr, WLAN_HEADER_LEN);
   memmove(buff+WLAN_HEADER_LEN, message, strlen(message));

   aWLAN->send(&buff, &daddr);
   return 0;
}
