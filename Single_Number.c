/*
136. Single Number

Given an array of integers, every element appears twice except for one. Find that single one.

Example 1:

Input: nums = [2,2,1]

Output: 1

Example 2:

Input: nums = [4,1,2,1,2]

Output: 4

Note:
Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
*/

#include <stdio.h>

/**
 * Function to find the single number in an array where
 * every other element appears exactly twice.
 */
int singleNumber(int* nums, int numsSize) {
    int i, k = 0;
    for (i = 0; i < numsSize; i++) {
        // The XOR operator (^) cancels out pairs
        k = k ^ nums[i]; 
    }
    return k;
}

int main() {
    // Test Case 1: 2s and 1s cancel, leaving 4
    int nums1[] = {4, 1, 2, 1, 2};
    int size1 = sizeof(nums1) / sizeof(nums1[0]);
    int result1 = singleNumber(nums1, size1);
    printf("Test Case 1 - Input: [4, 1, 2, 1, 2] | Result: %d\n", result1);

    // Test Case 2: 1s cancel, leaving 2
    int nums2[] = {2, 2, 1};
    int size2 = sizeof(nums2) / sizeof(nums2[0]);
    int result2 = singleNumber(nums2, size2);
    printf("Test Case 2 - Input: [2, 2, 1]       | Result: %d\n", result2);

    // Test Case 3: Single element array
    int nums3[] = {1};
    int size3 = 1;
    int result3 = singleNumber(nums3, size3);
    printf("Test Case 3 - Input: [1]             | Result: %d\n", result3);

    return 0;
}
