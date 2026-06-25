/*
Binary Number with Alternating Bits

Given a positive integer, check wheather it has alternating bits.
namely , if two adjacent bits will always have different values.
*/

#include <stdio.h>
#include <stdbool.h>

bool hasAlternatingBits(int n)
{
    long x = n ^ (n >> 1);
    return (x & (x + 1)) == 0;
}

int main(void)
{
    bool flag = hasAlternatingBits(5);

    if(flag) 
    {
        printf("number has alternating bits\n");
    }
}

/*
n = 21
n       =   1 0 1 0 1
n>>1    =   0 1 0 1 0
-------------------------
n ^ (n >>1) = 1 1 1 1 1     (all bits become 1)

x       =    1 1 1 1 1
x + 1  =   1 0 0 0 0 0
--------------------------
x & (X+1) = 0 0 0 0 0 0

*/