#include "comm.h"

int main()
{
    int msgid = CreateMsgQueue();
    char buf[64];

    //先发消息
    while(1)
    {
        printf("please Enter:");
        scanf("%s", buf);
        if(strncmp(buf, "quit", 4) == 0)
            break;
        SendMessage(msgid, buf, SERVER_TYPE);

        //接收消息
        RecMessage(msgid, buf, CLIENT_TYPE);
        printf("CLIENT#%s\n", buf);
    }

    DestoryMsgQueue(msgid);
    
    return 0;
}
