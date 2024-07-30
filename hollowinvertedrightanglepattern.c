#include<stdio.h>
int main()
{
    int i,j,n;
    printf("Enter number of rows : ");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        for(j=i;j<n;j++)
        {
            if(i==0||j==i||j==n-1)
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