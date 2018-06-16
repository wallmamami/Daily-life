#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

int main()
{
    int fd = open("fifo", O_WRONLY);//写端
    if(fd < 0)
    {
        perror("open");
        exit(1);
    }

    char buf[64];
    while(1)
    {
        printf("please Enter:");
        scanf("%[^\n]%*c", buf);
       if(strncmp(buf, "quit", 4) == 0)
           break;

       write(fd, buf, strlen(buf));
    }

    close(fd);
    return 0;
}
