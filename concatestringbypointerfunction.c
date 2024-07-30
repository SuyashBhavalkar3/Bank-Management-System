#include<stdio.h>
void strcon(char *,char *);
int main()
{
    char s1[10],s2[10];
    char *a;
    char *b;
    printf("Enter the string 1 : ");
    scanf("%s",s1);
    printf("Enter the string 2 : ");
    scanf("%s",s2);
    a=&s1[0];
    b=&s2[0];
    strcon(a,b);
    return 0;
}
void strcon(char *a,char *b)
{
    int i,j;
    char s[20];
   i=0;
   while(*a!='\0')
   {
    s[i]=*a;
    i++;
    a++;
   }
   j=0;
   while(*b!='\0')
   {
    s[i]=*b;
    b++;
    j++;
    i++;
   }
   s[i]='\0';
    printf("Concatenate string is : %s",s);
}