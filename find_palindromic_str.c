
// Question
// -------------------------------------------------------------------------- //

// Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

// A string is palindromic if it reads the same forward and backward.


// Example
// Example 1:

// Input: words = ["abc","car","ada","racecar","cool"]
// Output: "ada"
// Explanation: The first string that is palindromic is "ada".
// Note that "racecar" is also palindromic, but it is not the first.


#include <stdio.h>

char *firstPalindrome(char **words, int wordsSize)
{

    // assert
    int i = 0;
    char *empty_string = "";
        
    // traverse each string in the array
    for (; i < wordsSize; ++i)
    {
        if (IsPalindrome(words[i], strlen(words[i])))
        {
            return words[i];
        }
    }
    
    return empty_string;
}


int IsPalindrome(char *str_, size_t size_)
{
    char *begin = str_;
    char *end = (str_ + size_) - 1;
    
    while (begin < end)
    {
        if (*begin != *end)
        {
            return 0;
        }
        
        ++begin;
        --end;
    }
    
    return 1;
}

