#include "comm.h"

int main()
{
    int msgid = CreateMsgQueue();
    char buf[64];

    while(1)
    {
        //先接收消息
        RcvMessage(msgid, buf, CLIENT_TYPE);
        if(strncmp(buf, "quit", 4) == 0)
        {
            printf("client quit, me too!\n");
            break;
        }
        printf("CLIENT#%s\n", buf);

        //发送消息
        printf("Please Enter:");
        scanf("%s", buf);
        SendMessage(msgid, buf, SERVER_TYPE);

    }
    DestoryMsgQueue(msgid);
}
