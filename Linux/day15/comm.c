#include "comm.h"

int commMsg(int flag)
{
    key_t k = ftok(PATH_NAME, PROJ_ID);
    if(k < 0)
    {
        printf("ftok error");
        exit(1);
    }

   int msgid = msgget(k, flag);
   if(msgid < 0)
   {
       printf("msgget error!\n");
       exit(2);
   }

   return msgid;
}

int CreateMsgQueue()
{
    return commMsg(IPC_CREAT|IPC_EXCL|0666);
}

int GetMsgQueue()
{
    return commMsg(IPC_CREAT);
}

void SendMessage(int msgid, char* msg, int t)
{
    msgbuf buf;
    buf.mtype = t;
    strcpy(buf.mtext, msg);
    if(msgsnd(msgid, &buf, sizeof(buf.mtext), 0) < 0)
    {
        printf("msgsnd error!\n");
        exit(1);
    }

}


void RcvMessage(int msgid, char* msg, int t)
{
    msgbuf buf;
    buf.mtype = t;

    if(msgrcv(msgid, &buf, sizeof(buf.mtext), t, 0) < 0)
    {
        printf("msgrcv error!\n");
        exit(1);
    }

    strcpy(msg, buf.mtext);
}




void DestoryMsgQueue(int msgid)
{
    msgctl(msgid, IPC_RMID, NULL);
}
