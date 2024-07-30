#include<stdio.h>
void copystr(char *);
int main()
{
    char s1[10];
    char *a;
    printf("Enter the string : ");
    scanf("%s",s1);
    a=&s1[0];
    copystr(a);
    return 0;
}
void copystr(char *a)
{
    int i;
    char s[10];
    for(i=0;*a!='\0';i++)
    {
        s[i]=*a;
        a++;
    }
    s[i]='\0';
    printf("The copied string is : %s",s);
}