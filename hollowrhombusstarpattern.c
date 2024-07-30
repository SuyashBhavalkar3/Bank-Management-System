#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter the number of rows : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-i;j++)
        {
            printf(" ");
        }
        for(j=0;j<n;j++)
        {
            if(i==0||i==n-1||j==0||j==n-1)
            {
                printf("*");
            }
            else
            {
                printf(" ");
            }
        }
        printf("\n");
    }
}