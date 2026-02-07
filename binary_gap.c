/*
Given a position integer n , find and return the longest distance between any two adjecent 1's in the binary representation of n.
if there are no two adjecent 1's , return 0.

Two 1's are adjecent if there are only 0's seperating them.
The distance between 1's is the absolute difference between their bit positions.
For examples, the two 1's in 1001 have a distance of 3.

*/

#include<stdio.h>

int binaryGap(int n)
{
    int max_dist = 0;
    int last_pos = -1;
    int current_pos = 0;

    //Iterate through the bits of n using a loop
    while(n > 0){
        // Check if current last bit is 1
        if(n & 1){
            if(last_pos != -1){
                int dist = current_pos - last_pos;
                if( dist > max_dist){
                    max_dist = dist;
                }
            }
            last_pos = current_pos;
        }

        //Right shift n to check the next bit
        n >>= 1;
        current_pos++;
    }

    return max_dist;
}

int main(){
    int n1 = 22;        //Binary : 10110
    int n2 = 8;         //Binary : 1000
    int n3 = 5;         //Binary : 101


    printf("Longest distance for %d : %d\n",n1,binaryGap(n1));  //Output : 2
    printf("Longest distance for %d : %d\n",n2,binaryGap(n2));  //Output : 0
    printf("Longest distance for %d : %d\n",n3,binaryGap(n3));  //Output : 2

    return 0;
}