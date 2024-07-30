#include <stdio.h>

int main()
{
    int i, j;
    char s1[10];
    printf("Enter the string to be reversed (max 9 characters): ");
    scanf("%9s", s1); // Corrected to avoid buffer overflow

    // Find the length of the string
    for (i = 0; s1[i] != '\0'; i++)
        ;

    printf("Reverse of the string is: ");
    // Reverse print
    for (j = i - 1; j >= 0; j--)
    {
        printf("%c", s1[j]);
    }
    printf("\n");

    return 0;
}
