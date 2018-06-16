#include "comm.h"

int main()
{
    int msgid  = GetMsgQueue();
    char buf[64];

    while(1)
    {
        RecMessage(msgid, buf, SERVER_TYPE);
        if(strncmp(buf, "quit", 4) == 0)
        {
            printf("server quit, me too!\n");
            break;
        }

        printf("SERVER#%s\n", buf);


        printf("please Enter:");
        scanf("%s", buf);

        SendMessage(msgid, buf, CLIENT_TYPE);
    }
    
    return 0;
}
