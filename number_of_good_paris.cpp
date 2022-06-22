
#include <iostream>
#include <vector>

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
