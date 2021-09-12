#include <stdio.h>

void hannuo(int, char, char, char);



int main(void) 
{

    hannuo(4, 'A', 'B', 'C');

    return 0;

}

void hannuo(int n, char a, char b, char c) {

    if (n > 0)
    {
        if (n == 1)
        {
            printf("move %d from %c to %c \n", n, a, c);
        } 
        else 
        {

            hannuo(n-1, a, c, b);
            printf("move %d from %c to %c \n", n, a, c);
            hannuo(n-1, b, a, c);
        }
    }


}