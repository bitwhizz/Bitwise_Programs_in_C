/*
The Hamming distance between two integers is teh number of positions
at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

The process remains same : use the XOR operator to identify bits and 
then count how many bits in that result are set to 1.

Here is a clean implementation using Brian Kernighan's algorithm, 
which is highly efficient as it only loops as many times as there are set bits in the XOE result.
*/


#include <stdio.h>

int hammingDistance(int x,int y){
    int xor = x ^ y;
    int distance = 0;

    while(xor > 0){
        xor &= (xor -1);
        distance++;
    }

    return distance;
}

int main(){
    int x = 1, y = 4;
    printf("Hamming Distance : %d\n",hammingDistance(x,y));

    return 0;
}