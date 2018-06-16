#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
int main()
{
   int ret = mkfifo("fifo", 0644);
   if(ret < 0)
   {
       perror("mkfifo");
       exit(1);
   }

   int fd = open("fifo", O_RDONLY );//读端
   if(fd < 0)
   {
       perror("open");
       exit(1);
   }

   char buf[64];
   while(1)
   {
      size_t s = read(fd, buf, sizeof(buf)-1);
      if(s > 0)
      {
          buf[s] = '\0';
          printf("client# %s\n", buf);
      }

      else if(s == 0)
      {
          printf("server quit!\n");
          break;
      }
   }
        
       close(fd);
       return 0;
}
