// File: Sender.cpp
// Author: Michel Barbeau
// Version: January 16, 2016

#include "Sender.h"
#include "WLAN.h"
#include "label.h"

using namespace std;


Sender::Sender(int headerLen, int messageLen){
   char b[headerLen+messageLen];
   buff = &b;
}

Sender::~Sender(){
   delete buff;
}

Sender::buf(){
   return buff;
}


int main(int argc, char ** argv) {
   // char a[]="ff:ff:ff:ff:ff:ff"; // broadcast address
   char address[]="1c:bd:b9:7e:b6:5a"; // unicast address
   char message[]="This is a test frame"; // data


   int headerLen = aWLAN->getAddressLength()
   // create a sender
   Sender* aSender=new Sender(headerLen, strlen(message));
   // create a wireless network abstraction
   WLAN* aWLAN=new WLAN(LABEL);
   // initialize
   aWLAN->init();

   // Build Address
   WLAN::WLANAddr daddr;
   aWLAN->buildHeader(address, &daddr);

   // memmove probably need to be changed somehow
   memmove(aSender->buff(), &hdr, WLAN_HEADER_LEN);
   memmove(aSender->buff()+headerLen, message, strlen(message));

   aWLAN->send(aSender->buff(), &daddr);
   return 0;
}
