#include <stdio.h>
#include <string.h>
#include <stdlib.h>


void get_line(FILE* fp, char* buf, int len)//len是为了防止buf空间溢出
{
    int i = 0;
    char c;
    memset(buf, 0x00, len);

    do
    {
          c = fgetc(fp);
//          if(c == EOF)
//          {
//
//              exit(0);
//          }
          buf[i++] = c;
    }while(c!='\n' && i<len);
}


int main()
{
    char buf[1024] = {};

    printf("请输入要显示的文件名:");
    scanf("%s", buf);
    printf("buf=[%s]\n", buf);    
   FILE* fp =  fopen(buf, "r");
    if(NULL == fp)
    {
        perror("fopen error");
        exit(1);
    }

    while(!feof(fp))
    {
        get_line(fp, buf, 1024);
        int s = 0;
        int i = 0;
        for(; buf[i]!='\0'; i++)
        {
            if(buf[i] == ' ')
            {
                //如果是空格就将空格输出
                putchar(buf[i]);
                fflush(stdout);
                s = 0;
            }

            else if(buf[i] != ' ' && s == 0)
            {
                //进到单词里，就将单词输出完
                for(; buf[i]!=' '; i++)
                {
                    putchar(buf[i]);
                    fflush(stdout);
                    s = 1;
                }
                s = 0;
                sleep(1);
                i--;//因为这次循环出来i++了
            }
            

        }
    }
    


    fclose(fp);
}
