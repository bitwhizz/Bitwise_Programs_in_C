/*
Find even occuring elements in an array of limitted range.

The below method is using XOR operator as if we left shift 1 by 
value of each element of the array and take XOR of all the elements.


In _XOR_Container value 0 represents the even occurance
*/

#include<stdio.h>


//Function to find even occuring elements in given array
void printRepeatingEven(int array[],int nSize)
{
    long long _XOR_Container = 0L;
    long long pos;

    //do for each element of array
    for(int itemp=0; itemp < nSize;++itemp)
    {
         //left shift 1 by value of current elements.
        pos = 1 << array[itemp];       
         //Toggle the bit everytime elements gets repeated.
        _XOR_Container ^= pos;                   
    }
    /*Traverse the array again and use XOR 
    to find even occuring elements.*/
    for (int itemp=0; itemp < nSize; ++itemp)
    {
        pos = 1 << array[itemp];
        //Each 0 int _XOR_Container represent an even occurance.
        if(!(pos & _XOR_Container))          
        {
            printf("%d\n",array[itemp]);
            //Set the bits to avoid printing duplicates
            _XOR_Container ^= pos;            
        }
    }
}


int main(void)
{
    int u_array[]={12 ,5,8,44,60,12,5,1,1,33,44,9,23,54};
    int nsize = sizeof(long long) * __CHAR_BIT__;

    printRepeatingEven(u_array,nsize);

    return 0;    
}
