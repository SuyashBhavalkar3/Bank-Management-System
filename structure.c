#include<stdio.h>
struct student
{
    int id;
    int marks;
    char fav_char;
};
int main()
{
    struct student harry,ravi,shubham;
    harry.id=1;
    ravi.id=2;
    shubham.id=3;
    harry.marks=413;
    ravi.marks=466;
    shubham.marks=324;
    harry.fav_char='p';
    ravi.fav_char='h';
    shubham.fav_char='i';
    printf("Harry got %d marks",harry.marks);
    return 0;
}