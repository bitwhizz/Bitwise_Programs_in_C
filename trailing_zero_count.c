/*
Trailing zero count 

Given the Least significant 1 Bit and population count ( Ones Count) algorithm,
it is trivial to combine them to construct a trailing zero count.

*/

#include <stdio.h>

//Function to count set bits - ones count (Brian kernighans's Algorithm)
int count_set_bits(int n)
{
    int count = 0;
    while( n > 0)
    {
        n &= (n-1);
        count++;
    }
    return count;
}

unsigned int tzc(int num)
{
    return count_set_bits((num & -num) - 1);
}

int main(void)
{
    unsigned int trailing_zeros_count = 0;
    int num = 12;

    trailing_zeros_count = tzc(num);

    printf("trailing zeros of %d is %d",num,trailing_zeros_count);
}


/*

num = 12 ( 0000 1100)
-num = -12 ( 1111 0100)

Bitwize Anding num with its negation clears all the upper bits and isolates the least significant bit.
num & -num --> 000 0100

Subtracting 1 from a number that has exactly one set turns that bit into a 0 and flips all the lower 0's into 1's.
This perfectly crates a mask over the original trailing zeros.

0000 0100 - 1 --> 0000 0011

Notice that the number of 1's in this mask (0011 ) exactly matches the number of trailing zeros in the original number.


count the set bits.
*/