#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    close(1);//关闭标准输出
    int fd = open("file", O_WRONLY|O_CREAT, 0777);
    if(fd < 0)
    {
        perror("open");
    }

    printf("fd: %d\n", fd);
    fflush(stdout);

    close(fd);
    return 0;
    //    FILE* fp = fopen("mytext", "r");
    //
    //    if(NULL == fp)
    //    {
    //        perror("fopen");
    //    }
    //
    //    char* msg = "hello bit\n";
    //    char buf[1024];
    //    int count = 5;
    //
    //    while(count--)
    //    {
    //        fread(buf, strlen(msg), 1, fp);
    //    }
    //
    //    printf("%s ", buf);
    //
    //    fclose(fp);
    //    return 0;
}
