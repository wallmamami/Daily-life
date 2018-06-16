#include <stdio.h>
#include <string.h>


void BegNum()
{
    int i = 0;
    int num = 0;
    int count = 0;
    scanf("%d", &num);

    for(; i < 32; i++)
    {    
        if((1 & (num>>i)) == 1)
            count++;
    }
    printf("count: %d\n", count);
}



void MoveSteps()
{
    int num = 0;//要改的数
    int step = 0;//要移哪一位
    int flag = 0;//置零还是一
    int tmp = 1;

    scanf("%d%d%d", &num, &step, &flag);
    tmp = tmp << (step-1);//将1移到要改的那一位

    if(flag == 1)
    {
        num = num | tmp;//任何数或0都是他自己    
    }
    
    else
    {
        num = num & (~tmp);//tmp取反
    }

    printf("num = %d", num);
}


void BegNumop()
{
    int num = 0;
    int count = 0;
    scanf("%d", &num);

    while(num)
    {
        count++;
        num = num&(num-1);
    }

    printf("count = %d", count);

}
int main()
{
    //BegNum();//求整数中1的个数
   //BegNumop();
        
    MoveSteps();//将一个数的二进制数的任意一位置零或置一
   
    return 0;

}
