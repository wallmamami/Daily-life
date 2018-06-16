#include <stdio.h>
#include <unistd.h>

int main()
{
    printf("before execvp!\n");
    char* argv[] = {"./test", "a", "b","NULL"};
    execvp("./test", argv);
    printf("execvp error!\n");
}
