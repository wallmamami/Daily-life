#include "comm.h"


static int commMessage(int flag)
{
    key_t k = ftok(PATH_NAME, PROJ_ID);

    if(k < 0)
    {
        printf("ftok error!\n");
        return -1;
    }

    int msgid =  msgget(k, flag);
    if(msgid < 0)
    {
        printf("msgget error!\n");
        return -2;
    }

    return msgid;
}


int CreateMsgQueue()
{
    return commMessage(IPC_CREAT|IPC_EXCL|0666);
}

int GetMsgQueue()
{
    return commMessage(IPC_CREAT);
}


int SendMessage(int msgid, char* msg, int t)
{
    msgbuf buf;
    buf.mtype = t;

    strcpy(buf.mtext, msg);
    if(0 > msgsnd(msgid, &buf, sizeof(buf.mtext), 0))
    {
        printf("msgsnd error!\n");
        return -1;
    }
    return 0;
}

int RecMessage(int msgid, char* msg, int t)
{
    msgbuf buf;
    buf.mtype = t;

    if(0 > msgrcv(msgid, &buf, sizeof(buf.mtext), buf.mtype, 0))
    {
        printf("msgrcv error!\n");
        return -1;
    }
    strcpy(msg, buf.mtext);//接收消息是把消息队列中的消息拷贝到缓冲区
    return 0;
}

void DestoryMsgQueue(int msgid)
{
    msgctl(msgid, IPC_RMID, NULL);
}




