// Question
// -------------------------------------------------------------------------- //

// Given two strings s and t, determine if they are isomorphic.

// Two strings s and t are isomorphic if the characters in s can be replaced to get t.

// All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character, but a character may map to itself.


// Example 1:

// Input: s = "egg", t = "add"
// Output: true
// Example 2:

// Input: s = "foo", t = "bar"
// Output: false
// Example 3:

// Input: s = "paper", t = "title"
// Output: true



#define ASCI_SIZE 255

bool isIsomorphic(char *s_, char *t_)
{
    char map_s[ASCI_SIZE] = {0};
    char map_t[ASCI_SIZE] = {0};
    int i = 0;
    
    if (strlen(s_) != strlen(t_))
    {
        return 0;
    }
    
    // Create pairs of s_ letter index with t_ letter
    while (s_[i])
    {
        if (map_s[s_[i]] == 0 && map_t[t_[i]] == 0)
        {
            map_s[s_[i]] = t_[i];
            map_t[t_[i]] = s_[i];
        }
        else if (map_s[s_[i]] != t_[i] || map_t[t_[i]] != s_[i])
        {
            return 0;
        }
        
        ++i;
    }
    
    return 1;
}