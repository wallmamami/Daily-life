#include <stdio.h>
#include "add.h"
#include "sub.h"

int main()
{
    int x = 5;
    int y = 10;

    printf("add = %d sub = %d\n", add(x, y), sub(x, y));
    return 0;
}
