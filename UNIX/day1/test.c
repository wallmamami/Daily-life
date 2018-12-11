#include <unistd.h>
#include <stdio.h>

#define BUFFSIZE 4096

//使用 ./a.out < infile > outfile
//可以将infile中的文件拷贝到outfile

int main()
{
  int n;
  char buf[BUFFSIZE];

  //这里为什么可以一直读
  //read默认为阻塞接口，
  //假如一直读，这里不是应该会阻塞吗?
  //这里的STDIN_FILENO与STDOUT_FILENO
  //为两个宏,指定了标准输入和标准输出的fd
  while((n = read(STDIN_FILENO , buf, BUFFSIZE)) > 0)
  {
    if(write(STDOUT_FILENO, buf, n) != n)
    {
      perror("write");
    }
  }

  if(n < 0)
    perror("read");

  return 0;
}

