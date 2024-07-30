#include<stdio.h>
int main()
{
    int i,j;
    char s1[10],s[10];
    printf("Enter the string : ");
    scanf("%s",s1);
    for(i=0;s1[i]!='\0';i++)
    {
        s[i]=s1[i];
    }
    i--;
    for(j=i;j>=0;j--)
    {
        s[i]=s[j];
        printf("%c",s[i]);
    }
}