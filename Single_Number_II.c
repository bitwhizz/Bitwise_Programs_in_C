/*
137. Single Number II

Given an array of integers, every element appears three times except for one, which appears exactly once. Find that single one.

Example 1:

Input: nums = [2,2,3,2]
Output: 3
Example 2:

Input: nums = [0,1,0,1,0,1,99]
Output: 99

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>

/**
 * Finds the element that appears once in an array where 
 * all other elements appear three times.
 */
int singleNumber(int* nums, int numsSize) {
    int i, ones, twos;
    ones = twos = 0;
    
    for (i = 0; i < numsSize; i++) {
        /*
         * 'ones' tracks bits that have appeared 1 time (mod 3)
         * 'twos' tracks bits that have appeared 2 times (mod 3)
         * When a bit appears a 3rd time, it is cleared from both.
         */
        ones = (ones ^ nums[i]) & ~twos;
        twos = (twos ^ nums[i]) & ~ones;
    }
    
    return ones;
}

int main() {
    // Test Case 1: 2s appear three times, 3 appears once.
    int nums1[] = {2, 2, 3, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = singleNumber(nums1, size1);
    printf("Test Case 1 - Input: [2, 2, 3, 2]       | Result: %d\n", result1);

    // Test Case 2: 0s and 1s appear three times, 99 appears once.
    int nums2[] = {0, 1, 0, 1, 0, 1, 99};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = singleNumber(nums2, size2);
    printf("Test Case 2 - Input: [0, 1, 0, 1, 0, 1, 99] | Result: %d\n", result2);

    return 0;
}

