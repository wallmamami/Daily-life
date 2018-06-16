#include "comm.h"


int main()
{
    int msgid = GetMsgQueue();
    char buf[64];

    while(1)
    {
        printf("Please Enter:");
        scanf("%s", buf);
        SendMessage(msgid, buf, CLIENT_TYPE);
        if(strncmp(buf, "quit", 4) == 0)
        {
            printf("quit, buy!\n");
            break;
        }

        RcvMessage(msgid, buf, SERVER_TYPE);
        printf("SERVER#%s\n", buf);

    }
    return 0;
}
