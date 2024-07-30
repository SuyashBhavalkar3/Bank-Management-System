#include<stdio.h>
int main()
{
    int  i,j,a,b,c,d;
    int m[10][10];
    printf("Enter number of rows of matrix 1 : ");
    scanf("%d",&a);
    printf("Enter number of column of matrix 1 : ");
    scanf("%d",&b);
    printf("Enter number of rows of matrix 2 : ");
    scanf("%d",&c);
    printf("Enter number of column of matrix 2 : ");
    scanf("%d",&d);
    printf("Enter elements of matrix 1 :\n");
    for(i=1;i<=a;i++)
    {
        for(j=1;j<=b;j++)
        {
            scanf(" %d",& m[i][j]);
        }
    }
    printf("Matrix 1 is :\n ");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            printf(" %d",m[i][j]);
        }
         printf(" \n");
    }
}