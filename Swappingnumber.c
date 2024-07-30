//Swap Two Numbers
#include<stdio.h>
int  main()
{
    int a,b,c;
    printf("Enter number 1 : ");
    scanf("%d",&a);
    printf("Enter Number 2 : ");
    scanf("%d",&b);
    printf("After Swapping");
    c=a;
    a=b;
    b=c;
    printf("\nNumber 1 is : %d ",a);
    printf("\nNumber 2 is : %d ",b);
}