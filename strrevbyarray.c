#include<stdio.h>
int main()
{
    char s2[10],s1[10],s[10];
    int i,j,k=0;
    printf("Enter the String : ");
    scanf("%s",&s2);
    for(i=0;s2[i]!='\0';i++)
    {
        s[i]=s2[i];
    }
    i--;
    for(j=i;j>=0;j--)
    {
        s[k]=s2[j];
        k++;
    }
    s[k]='\0';
    printf("The reversed string is : %s",s);
}