
// Question
// -------------------------------------------------------------------------- //

// Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

// You must write an algorithm with O(log n) runtime complexity.

// Example 1:
// Input: nums = [-1,0,3,5,9,12], target = 9
// Output: 4
// Explanation: 9 exists in nums and its index is 4

// Example 2:
// Input: nums = [-1,0,3,5,9,12], target = 2
// Output: -1
// Explanation: 2 does not exist in nums so return -1

// Constraints:
//     1 <= nums.length <= 104
//     -104 < nums[i], target < 104
//     All the integers in nums are unique.
//     nums is sorted in ascending order.

// -------------------------------------------------------------------------- //

#include <iostream>
#include <vector>

// Solution 1:  Recursive
class Solution {
public:
    int search(std::vector<int>& nums_, int target_) 
    {       
        return BinarySearch(nums_, nums_.begin(), nums_.end() - 1, target_);
    }

private:
    int BinarySearch(std::vector<int>& nums_, std::vector<int>::iterator left_, std::vector<int>::iterator right_, int target_)
    {
        if (left_ <= right_)
        {
            std::vector<int>::iterator itrPivot = left_ + (right_ - left_)/2;
            
            // check if target stands on current iterator
            if (target_ == *itrPivot)
            {
                return std::distance(nums_.begin(), itrPivot);
            }

            // target is in the right portion
            if (target_ < *itrPivot)
            {
                return BinarySearch(nums_, left_, itrPivot - 1, target_);
            }

            // target is in the left portion
            return BinarySearch(nums_, itrPivot + 1, right_, target_);
        }
        
        return -1;
    }
};

// Edge Cases
//
//  1. target is on the left
//  2. target is on the right
//  3. target is on current element
//  4. target does not exists

// Pseudo-Code
//
// get the size of the array
// divide the array to two

// if element equals to target
//      return element index

// if the target is smaller than target
//      find the mid element in the left portion.
//      invoke Search again

// if the target is bigger than target
//      find the mid element in the right portion.
//      invoke Search again


// In case target does not exists return -1

// -------------------------------------------------------------------------- //


// Iterative Way

// Solution 1:  Iterative
class Solution {
public:
    int search(std::vector<int>& nums_, int target_) 
    {
        int left = 0;
        int right = nums_.size() - 1;

        while (left <= right)
        {
            int pivot = left + (right - left) / 2;

            // In case target is present at pivot, and return when found
            if (target_ == nums_[pivot])
            {
                return pivot;
            }

            // In case target is smaller than pivot value, update right index
            if (target_ < nums_[pivot])
            {
                right = pivot - 1;
            }

            // target is bigger than pivot value, update left index
            else
            {
                left = pivot + 1;
            }
        }

        return -1;
    }
};