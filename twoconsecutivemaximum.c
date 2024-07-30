#include<stdio.h>
#include<limits.h>
void arraymin(int a[]);
int main()
{
    int a[10];
    int i,n;
    printf("Enter limit of array (<10) : ");
    scanf("%d",&n);
    printf("Enter numbers : \n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
    arraymin( a, n );
}
    void arraymin(int b[],int n)
    {
        int i,c,k;
    k=b[0];
    c=INT_MAX;
    for(i=0;i<n;i++)
    {
        if(k>b[i])
        {
            k=b[i];
        }
        else if (c>b[i]&&b[i]>k)
        {
            c=b[i];
        }
    }
    printf("The first minimum number is :\t %d",k);
    printf("\nThe second minimum number is :\t %d",c);
}


