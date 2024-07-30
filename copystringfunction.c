#include <stdio.h>
void scopy(char []);
int main()
{
    char s[10];
       printf("Enter the string to be copied : ");
    scanf("%s",s);
    scopy(s);
}
void scopy(char s[])
{
    char s1[10];
    int i;
    i=0;
    while(s[i]!='\0')
    {
        s1[i]=s[i];
        i++;
    }

    s1[i]='\0';
    printf("Copied string is : %s ",s1);
}
