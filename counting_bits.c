
// Question
// -------------------------------------------------------------------------- //

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

// Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.


int CountBits(int num);
int CountBitsNoLoop(int num);
int CountBitsHW(int x);


//
// Solution 1 - build an LUT using solution 3
int* countBits(int n, int* returnSize)
{
    // assert
    
    // allocate / create an array the size of n+1
    *returnSize = n + 1;
    int total_length = *returnSize;
    
    int *bits_arr = (int*)malloc(total_length * sizeof(int));
    int i = 0;
    
    // iterate in each index
    for (i = 0; i < total_length; i++)    
    {
        // Count the Set bits of each index_number
        // assign the result to the current index
        bits_arr[i] = CountBitsNoLoop(i);
    }
    
    // return the array
    return bits_arr;
}


//
// Solution 2 - Simple Iteration
// Complexity O(n)
int CountBits(int num)
{
    const int MASK = 1;
    int counter = 0;
    
    while (num > 0)
    {
        if (!!(MASK & num))
        {
            ++counter;
        }
        
        num >>= 1;
    }
    
    return counter;
}


//
// Solution 3 - Trick Solution
// Complexity O(num_of_set_bits)
int CountBitsNoLoop(int num)
{
    const int MASK = 1;
    int counter = 0;
    
    while (num > 0)
    {
        num = (num & (num - 1));
        ++counter;
    }
    
    return counter;
}



//
// Solution 4 - HammingWeight
const uint64_t m1  = 0x5555555555555555; //binary: 0101...
const uint64_t m2  = 0x3333333333333333; //binary: 00110011..
const uint64_t m4  = 0x0f0f0f0f0f0f0f0f; //binary:  4 zeros,  4 ones ...
const uint64_t m8  = 0x00ff00ff00ff00ff; //binary:  8 zeros,  8 ones ...
const uint64_t m16 = 0x0000ffff0000ffff; //binary: 16 zeros, 16 ones ...

int CountBitsHW(int x)
{
    x = (x & m1 ) + ((x >>  1) & m1 ); //put count of each  2 bits into those  2 bits 
    x = (x & m2 ) + ((x >>  2) & m2 ); //put count of each  4 bits into those  4 bits 
    x = (x & m4 ) + ((x >>  4) & m4 ); //put count of each  8 bits into those  8 bits 
    x = (x & m8 ) + ((x >>  8) & m8 ); //put count of each 16 bits into those 16 bits 
    x = (x & m16) + ((x >> 16) & m16); //put count of each 32 bits into those 32 bits 
    return x;
}