#include<stdio.h>
void add(int , int );
int main()
{
    int a,b;
    printf("Enter number 1 : ");
    scanf("%d",&a);
    printf("Enter number 2 : ");
    scanf("%d",&b);
    add(a,b);
}
void add(int x, int y)
{
    int z;
    z=x+y;
    printf("The addition of %d and %d is : %d ",x,y,z);
}