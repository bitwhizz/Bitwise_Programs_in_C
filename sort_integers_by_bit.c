/*
Sort integers by the Number of 1 bits.

you are given an integer array arr.

Sort the integers in the array in ascending order by the the numbers of 1's in their binary representation 
and in case of two or more integers have the same number of 1's you have to sort them in ascending order.

Return the array after sorting it.
*/

#include <stdio.h>


//Function to count set bits (Brian kernighans's Algorithm)
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

void sortByBits(int *arr, int arrSize)
{
    for(int i = 0;i < arrSize - 1 ;i++){
        for(int j = 0;j < arrSize - i - 1;j++){
            int bits1 = count_set_bits(arr[j]);
            int bits2 = count_set_bits(arr[j+1]);

            //condition 1 : sort by number of 1s ascending
            //condition 2 : If bits are equal , sort by numerical value ascending
            if(bits1 > bits2 || (bits1 == bits2 && arr[j] > arr[j + 1]))
            {
                //swap the elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(void)
{
    int arr[] = {7,8,3,0,1,2,5,6,4};
    int size = sizeof(arr) / sizeof(arr[0]);

    sortByBits(arr,size);


    int stackarray[32] = {0};
    int top = -1;

    printf("Sorted array : \n");
    for(int i = 0; i < size;i++){
        printf("%d -> ",arr[i]);

        while(arr[i])
        {
            if(arr[i] % 2 == 1){
                stackarray[++top] = 1;
            }
            else{
                stackarray[++top] = 0;
            }
            arr[i] >>= 1;
        }

        while(top != -1)
        {
            printf("%d",stackarray[top--]);
        }
        printf("\n");
    }
    printf("\n");

    return 0;
}
