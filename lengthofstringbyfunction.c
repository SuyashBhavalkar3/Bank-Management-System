#include<stdio.h>
void slen(char[]);
int main()
{
    char a[10];
    printf("Enter the string of which length is to be calculated : ");
    scanf("%s", a);
    slen(a);
    return 0;
}
void slen(char s[])
{
    int i;
    int count=0;
    for(i=0;s[i]!='\0';i++)
    {
    }
    printf("Length of entered string is : %d", i);
}