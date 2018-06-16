#include <stdio.h>


void FindNum(int (*arr)[4], int row, int col, int num)
{
    int Row = 0;
    while(Row <= row-1 && (col-1) >= 0)
    {
        if(arr[Row][col-1] == num)
        {
            printf("找到了!!!\n");
            return;
        }
        else if(arr[Row][col-1] > num)
            col -= 1;//去除一列
        else
            Row += 1;//去除一行
    }

    printf("找不到!!!\n");
}

int main()
{
    int arr[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
    int row = 3;
    int col = 4;
    int num = 0;

    scanf("%d", &num);
    FindNum(arr, row, col, num);
    return 0;
}
