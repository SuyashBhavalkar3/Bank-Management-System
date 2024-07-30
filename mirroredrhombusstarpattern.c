#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(i=n;i>=1;i--)
    {
        for(j=n-i;j>=1;j--)
        {
            printf(" ");
        }
        for(j=n;j>=1;j--)
        {
            printf("*");
        }
        printf("\n");
    }
}