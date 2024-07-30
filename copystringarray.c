#include<stdio.h>
int main()
{
    int i;
    char s1[10],s[10];
    printf("Enter the string : ");
    scanf("%s",s1);
    for(i=0;s1[i]!='\0';i++)
    {
        s[i]=s1[i];
    }
    s[i]='\0';
    printf("Copied string is : %s",s);
}