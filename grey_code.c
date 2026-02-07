/*
An n-bit gray code sequence is a sequence of 2^n integers

where :

*Every integer is in the inclusive range [0,2^n -1],
*The first integer is 0,
*An integer appears no more than once in the sequence,
*The binary representation of every pair of adjacent integers differs by exactly one bit.
*The binary representtaion of the first and last integers differs by exactly one bit.

*/

#include<stdio.h>
#include<stdlib.h>

/*
Note: The returned array must be malloced,
assume callers call free().
*/

int* grayCode(int n,int* returnSize){
    //TOtal number of elements in an n-bit sequence is 2^n
    *returnSize = 1 << n;
    int* result = (int*)malloc((*returnSize)*sizeof(int));

    if(result == NULL) return NULL;

    for(int i = 0;i < *returnSize;i++){
        //Gray code formula : i ^ (i / 2)
        result[i] = i ^ (i >> 1);
    }

    return result;
}

int main()
{
    int n = 3;
    int size;
    int* code = grayCode(n, &size);

    printf("Gray code for n = %d:\n",n);

    for(int i = 0; i < size;i++){
        printf("%d",code[i]);
    }
    free(code);
    return 0;
}