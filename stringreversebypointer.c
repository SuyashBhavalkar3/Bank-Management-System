#include<stdio.h>
void strrev(char *);
int main()
{
    char s1[10];
    char *d;
    printf("Enter the string to be reversed : ");
    scanf("%s",s1);
    d=&s1[0];
    strrev(d);
    return 0;
}
void strrev(char *d)
{
    char s3[10];
    char *s=&s3[0];
    int i,j;
    for(i=0;*d!='\0';i++)
    {
        d++;
       // s[i]=*d;
    }
    d--;
    i--;
    for(j=i;j>=0;j--)
    {
        *s=*d;
        d--;
        s++;
    }
    *s='\0';
    printf("Reversed String is : %s",s3);
}