/*
Number of Bits Changes to Make two integers Equal

you are given two poitive integers n and k;

you can choose any bit in the binary representation of n that is equal to 1 
and changes it to 0;

Return the number of changes needed to make n equal to k.
if it is imposible , return -1.
*/

#include <stdio.h>

int minChanges(int n, int k)
{
    if((n & k)!=k){
        return -1;
    }

    int diff = n ^ k;
    int changes = 0;

    while(diff > 0)
    {
        changes += (diff & 1);
        diff >>= 1;
    }

    return changes;
}

int main(void)
{
    int num_bits = 0;

    num_bits = minChanges(13,4);

    printf("Number of bits to change n to k is %d\n",num_bits);

}
