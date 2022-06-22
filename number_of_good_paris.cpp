
// Question
// -------------------------------------------------------------------------- //

// Given an array of integers nums, return the number of good pairs.

// A pair (i, j) is called good if nums[i] == nums[j] and i < j.


// Example 1
// Input: nums = [1,2,3,1,1,3]
// Output: 4
// Explanation: There are 4 good pairs (0,3), (0,4), (3,4), (2,5) 0-indexed.

// Example 2

// Input: nums = [1,1,1,1]
// Output: 6
// Explanation: Each pair in the array are good.


#include <iostream>
#include <vector>

// Complexity O(n^2)
class Solution 
{
public:
    int numIdenticalPairs(std::vector<int>& nums_) 
    {
        size_t size = nums_.size();
        int counter = 0;
        
        for (size_t i = 0; i < size - 1; i++)
        {
            for (size_t j = i+1; j < size; j++)
            {
                if (nums_[i] == nums_[j])
                {
                    ++counter;
                }
            }
        }
        
        return counter;
    }
};


int main()
{
    Solution obj;
    std::vector<int> input{1,2,3};
    int counter;

    counter = obj.numIdenticalPairs(input);

    std::cout << counter << std::endl;

    return 0;
}
