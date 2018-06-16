#ifndef __COMM_H__
#define __COMM_H__

#define PATH_NAME "./tmp"
#define PROJ_ID 0x7777

#define SERVER_TYPE 1
#define CLIENT_TYPE 2

typedef struct msgbuf
{
    long mtype;
    char mtext[64];
}msgbuf;


#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <stdlib.h>
#include <stdio.h>


int CreateMsgQueue();
int GetMsgQueue();
void DestoryMsgQueue(int msgid);
void SendMessage(int msgid, char* msg, int t);
void RcvMessage(int msgid, char* msg, int t);

#endif
