#include<stdio.h>
int main()
{
    int num,i,fact;
    fact=1;
    printf("Enter the number of which factorial is to be found : ");
    scanf("%d",&num);
    i=1;
    while(i<=num)
    {
        fact=fact*i;
        i++;
    }
    printf("Factorial of %d is : %d",num,fact);
}