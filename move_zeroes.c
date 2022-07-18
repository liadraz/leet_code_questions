// Question
// -------------------------------------------------------------------------- //

// Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

// Note that you must do this in-place without making a copy of the array.

// Example 1:

// Input: nums = [0,1,0,3,12]
// Output: [1,3,12,0,0]
// Example 2:

// Input: nums = [0]
// Output: [0]


// In-Place
// Maintain the relative order


void moveZeroes(int* nums_, int numsSize_)
{
    // pointer for dest
    int *dest = nums_;
    // pointer for src
    int *src = nums_;
    
    int *end = nums_ + numsSize_;
    
    // traverse the array
    while (src < end)
    {
        // once src encountered with zero
        if (*src == 0)
        {
            // increment src by one
            ++src;
        }
        
        // copy src to dest
        *dest = *src;
        
        // increment src and dest pointers
        ++dest;
        ++src;
    }
    
    // Zero the left elements
    while (dest < end)
    {
        *dest = 0;
        ++dest;
    } 
}


#include <stdio.h>

int main() {
    // Write C code here
    int nums[] = {0,1,0,3,12};
    moveZeroes(nums, 5);
    
    for (int i = 0; i < 5; ++i)
    {
        printf("%d ", nums[i]);
    }

    printf("\n");

    int nums2[] = {0};
    moveZeroes(nums2, 1);

    for (int i = 0; i < 1; ++i)
    {
        printf("%d ", nums2[i]);
    }

    return 0;
}