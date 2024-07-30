#include<stdio.h>
int main()
{
    int i;
    int count=0;
    char s[10];
    printf("Enter the string : ");
    scanf("%s",&s);
    for(i=0;s[i]!=0;i++)
    {
        count++;
    }
    printf("The length of the string is : %d ",count);
}