#include<stdio.h>
int main()
{
    int i,j;
    char s1[10],s2[10],s[10];
    printf("Enter the string 1 : ");
    scanf("%s",&s1);
    printf("Enter the string 2 : ");
    scanf("%s",&s2);
    for(i=0;s1[i]!='\0';i++)
    {
        s[i]=s1[i];
    } 
    for(j=0;s[j]!='\0';j++)
    {
        s[i]=s2[j];
        i++;
    }
        s[i]='\0';
    printf("The concatenate string is : %s",s);
}