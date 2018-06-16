#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main()
{
    int fd = open("mytest", O_RDONLY);

    if(fd == 0)
    {
        perror("open");
    }

    const char* msg = "hello bit\n";
    int count = 5;
    char buf[50];

    while(count--)
    {
       size_t s = read(fd, buf, strlen(msg));

        if(s > 0)
        {
            buf[s] = 0;
        }

       printf("%s", buf);
       // write(fd, msg, strlen(msg));
    }
//    FILE* fp = fopen("mytest", "a+");
//    
//    if(fp == NULL)//打开失败
//    {
//        perror("fopen");
//    }
//
//  char* ptr = "hello bit!";
//  int count = 5;
//
//  while(count--)
//  {
//      fwrite(ptr, sizeof(char), strlen(ptr), fp);
//  }
//
  close(fd);
  return 0;
}
