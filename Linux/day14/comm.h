#ifndef __COMM_H__
#define __COMM_H__

#include <stdio.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/msg.h>
#include <string.h>

#define SERVER_TYPE 1
#define CLIENT_TYPE 2



typedef struct msgbuf
{
    long mtype;
    char mtext[64];
}msgbuf;

void DestoryMsgQueue(int msgid);
int RecMessage(int msgid, char* msg, int t);
int SendMessage(int msgid, char* msg, int t);
int CreateMsgQueue();
int GetMsgQueue();




#define PATH_NAME "./tmp"
#define PROJ_ID 0x6666


#endif
