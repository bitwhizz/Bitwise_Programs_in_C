/*
Check if binary representation of a number is Palindrome.

EX : 0x99 --> 1001 1001
*/

#include<stdio.h>
#include<stdbool.h>

bool isKthbitset(unsigned int num,unsigned int k)
{
    return (num & (1 << (k-1))) ? true : false;
}

/*
 function isPalindrome returns true if 
 binary representation of num is palindrome.
*/

bool isPalindrome(unsigned int num)
{
    //initialize the left position
    unsigned int left = 1; 

    //Initialize the right position
    unsigned int right = sizeof(unsigned int)*__CHAR_BIT__; 

    //one by one compare the bits
    while(left < right)
    {
        if(isKthbitset(num,left) != isKthbitset(num,right))
            return false;

        left++ ; right--;
    }
    return true;
}

int main(void)
{
    unsigned int Xvar = 0XC0000003;     //utilizing the full bit space
    bool status = false;

    status=isPalindrome(Xvar);

    if(status == true)
        printf("Binary representation of a number is palindrome\n");
    else
        printf("Binary representation of a number is not a palindrome\n");

    return 0;
}

