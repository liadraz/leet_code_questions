
// Question
// -------------------------------------------------------------------------- //

// Given two strings ransomNote and magazine, return true if ransomNote can be constructed by using the letters from magazine and false otherwise.

// Each letter in magazine can only be used once in ransomNote.


// Example 1:

// Input: ransomNote = "a", magazine = "b"
// Output: false
// Example 2:

// Input: ransomNote = "aa", magazine = "ab"
// Output: false
// Example 3:

// Input: ransomNote = "aa", magazine = "aab"
// Output: true


#include <stdio.h>
#include <stdbool.h>

#define ASCI    256


bool canConstruct(char *ransomNote, char *magazine)
{
    int i = 0;
    char* runnerN = ransomNote; //  'aa'
    char* runnerM = magazine;   //  'aab'
        
    assert(NULL != ransomNote);
    assert(NULL != magazine);
    
    
    // traverse magazine string and store each in the LUT array
    int letter_lut[ASCI] = {0};
    
    
    while (*runnerM != '\0')
    {
        letter_lut[*runnerM] += 1;
        ++runnerM;
    }
    
    
    // traverse ransomNote and decrement letters that exists in the LUT array
    while (*runnerN != '\0')
    {
        if (letter_lut[*runnerN] == 0)
        {
            return false;
        }
        
        --letter_lut[*runnerN];
        ++runnerN;
    }
    
    return true;
}