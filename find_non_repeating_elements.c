/*
Find the two non-repeating elements in an array of repeating elements.

for a single non repeating element the approach is simple as 
we Xor the all the elements in a array and traverse the array with 
xored value check for the odd in Xored value the element with odd bit
set gives the sing non repeating value.

logic to find the two non-repeating elements in an array of repeating element 
is either of the two non repeating elements have this set bit , based on 
this check we can differentiate this two numbers.

*/

#include <stdio.h>

void get2nonrepeatingNos(int array[],unsigned int n ,int *x,int *y)
{
    int _XOR_Container = array[0];
    int set_bit_no = 0;

    int itemp = 0;
    *x = 0;
    *y = 0;

    /*Get XOR of all elements*/
    for(itemp = 1;itemp<n;itemp++){
        _XOR_Container ^= array[itemp];
    }

    /*set_bit_no holds one of the first set bit of XORed value.
    first set bit in XORed array holdings set bits for
     non repeating elements in an array */
    set_bit_no = _XOR_Container & ~(_XOR_Container-1);

    for (itemp=0 ; itemp<n ; itemp++){
        if(array[itemp] & set_bit_no)
            *x = *x ^ array[itemp];
        else
            *y = *y ^ array[itemp];
    }
}

int main(void)
{
    int non_repeating_no_1 = 0 , non_repeating_no_2 = 0;

    int array[] = { 33, 24 ,33 , 50 , 21 , 8 , 2 , 9 , 24 , 8 ,2 ,21};

    unsigned int size = sizeof(array)/sizeof(array[0]);

    get2nonrepeatingNos(array,size,&non_repeating_no_1,&non_repeating_no_2);

    printf("Two non repeating numbers in an array of \
    repeating numbers are %d and %d\n", non_repeating_no_1,non_repeating_no_2);

    return 0;
}
