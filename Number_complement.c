/*
The complement of a n integer is the integer you get when you flip all the 0's to 1's
and all the 1's to 0's in its binary representation.

EX : 
    The integer 5 is "101" in binary and its complement is "010" which is integer 2.

Given an integer num , return its complement.
*/


#include <stdio.h>

int find_complement(int num)
{
    if(num == 0) return 1;

    unsigned int mask = ~0;

    while(num & mask)
    {
        mask <<= 1;
    }

    return num ^ ~mask;
}


int main(void)
{
    int num = 5;
    int result = 0;

    result = find_complement(num);

    printf("complement of number %d is %d\n",num,result);

    return 0;
}