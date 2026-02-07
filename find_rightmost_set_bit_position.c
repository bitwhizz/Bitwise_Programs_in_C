#include <stdio.h>

int findRightmostSetBit(int num)
{
    if(num == 0) return -1;

    //Isolate the rightmost set bit
    int rightmost = num & -num;     //or : num & (~num + 1)

    //Convert to position 
    int position = 0;
    while(rightmost > 1){
        rightmost >>= 1;
        position++;
    }

    return position;
}


int main(void)
{

    printf("rightmost position of the \
    set bit in a number is %d \n",findRightmostSetBit(0x80));

}