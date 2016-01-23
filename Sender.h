// File: Sender.h
// Author: Michel Barbeau
// Version: January 16, 2016

class Sender {
public:
  Sender(int headerLen, int messageLen);
  ~Sender();
  char* buff();
private:
  char* buffFrame;
};
