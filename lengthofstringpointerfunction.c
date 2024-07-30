#include<stdio.h>
void slen(char *);
int main()
{
    char *p;
    char s[10];
    printf("Enter the string : ");
    scanf("%s",s);
    p=&s[0];
    slen(p);
    return 0;
}
void slen(char *p)
{
    int t=0,i;
    for(i=0;*p!='\0';i++)
    {
        t++;
        p++;
    }
    printf("Length of the string  is : %d ",t);
}