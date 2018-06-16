#include <stdio.h>
#include <stdlib.h>

int fib(int n)
{
    int arr[n+1];
    int i = 0;
    arr[0] = 0;
    arr[1] = 1;
    arr[2] = 1;

    for(i=3; i<n+1; i++)
    {
        arr[i] = arr[i-1] + arr[i-2];
    }
    
    return arr[n];
}


int main( )
{
    int n;//求菲比那切数列的第n项

    printf("n: ");
    scanf("%d", n);

    int ret = fib(n);

    printf("ret = %d\n", ret);
    return 0;
}
