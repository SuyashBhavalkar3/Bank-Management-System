#include<stdio.h>
int main()
{
    int i,j;
    char s1[10],s2[10],s[20];
    printf("Enter string 1 : ");
    scanf("%s",s1);
    printf("Enter string 2 : ");
    scanf("%s",s2);
    for(i=0;s1[i]!='\0';i++)
    {
        s[i]=s1[i];
    }
    for(j=0;s2[j]!='\0';j++)
    {
        s[i]=s2[j];
        i++;
    }
    s[i]='\0';
    printf("Concatenated string is : %s",s);
}