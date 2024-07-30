#include<stdio.h>
int main()
{
    int a,b,i,j;
    int m[10][10];
    int t[10][10];
    printf("Enter no of rows of matrix: ");
    scanf("%d",&a);
    printf("Enter no of columns of matrix: ");
    scanf("%d",&b); 
    printf("Enter the elements of matrix :\n ");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            scanf("%d",&m[i][j]);
        }
    }
    printf("The matrix should be :\n");

 for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
           printf("  %d",m[i][j]);
        }
        printf("\n");
    }
    printf("Trnaspose matrix should be :\n");
    for(i=0;i<a;i++)
    {
        for(j=0;j<b;j++)
        {
            t[i][j]=m[j][i];
           printf("  %d",t[i][j]);
        }
        printf("\n");
    }
}
