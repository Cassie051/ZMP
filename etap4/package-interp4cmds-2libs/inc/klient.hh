//
// Created by kasia on 26.11.2020.
//

#ifndef INTERPRETER_KLIENT_HH
#define INTERPRETER_KLIENT_HH

#include <iostream>
#include <iomanip>
#include <cstring>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <thread>
#include <mutex>
#include <vector>
#include "AccessControl.hh"
#include "Port.hh"
#include "Sender.hh"
#include "MobileObj.hh"

void Fun_CommunicationThread(Sender  *pSender);
bool OpenConnection(int &rSocket);
bool ExecCmd(MobileObj *pObj, AccessControl  *pAccCtrl);
int Exec(Scene &scene);


#endif //INTERPRETER_KLIENT_HH
