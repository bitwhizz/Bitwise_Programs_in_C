/*
Given an integer n, return true if it is a power of four. otherwisw, return false.

An integer n is a power of four, if there exists an integer x such that n == 4^x.
*/


#include <stdio.h>
#include <stdbool.h>

int main(void)
{
    unsigned int v = 256; // we want to see if v is a power of 4
    bool f=false;      // the result goes here 


    f = v && !(v & (v - 1)) && (v & 0x55555555) != 0;

    if(f == true)
    {
        printf("the given integer %d is power of four\n",v);
    }  
    else{
        printf("is not a power of four\n");        
    }

    v = 16;
    f=false;

    f = v && !(v & (v - 1)) && (v % 3 == 1);

    if(f == true)
    {
        printf("the given integer %d is power of four\n",v);
    }  
    else{
        printf("is not a power of four\n");        
    }
    
    return 0;
}
