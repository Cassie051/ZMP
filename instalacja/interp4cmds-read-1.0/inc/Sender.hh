//
// Created by kasia on 26.11.2020.
//
#include "Scene.hh"
#include <unistd.h>
#include <cstring>
#ifndef INTERPRETER_SENDER_H
#define INTERPRETER_SENDER_H

class Sender {

    volatile bool    _ContinueLooping = true;

    int             _Socket = 0;

    Scene          *_pScn = nullptr;


public:

    Sender(int Socket, Scene *pScn);

    bool ShouldCountinueLooping();

    void CancelCountinueLooping();

    void Watching_and_Sending();
    int Send(int Sk2Server, const char *sMesg);

};

#endif //INTERPRETER_SENDER_H
