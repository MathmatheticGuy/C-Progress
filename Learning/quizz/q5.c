#include <stdio.h>
#include <stdlib.h>

int top = 0;

char fun1()
{
    char a[] = {'a', 'b', 'c', '(', 'd'};
    return a[top++];
}

int main()
{
    char b[10];
    char ch2;
    int i = 0;

    while ((ch2 = fun1()) != '\0') // Corrected the syntax error in the while loop condition
    {
        b[i++] = ch2;
    }

    b[i] = '\0'; // Add null-terminating character to mark the end of the string

    printf("%s", b);

    return 0;
}