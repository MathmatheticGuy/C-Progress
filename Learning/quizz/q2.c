#include <stdio.h>

int main()

{
    // check number range in sizeof()
    int i = 12;

    int j = sizeof(i++);

    printf("%d  %d", i, j);

    return 0;

}