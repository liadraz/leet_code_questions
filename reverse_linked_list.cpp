
// Question
// -------------------------------------------------------------------------- //

// Given the head of a singly linked list, reverse the list, and return the reversed list.

// Example 1
// Input: head = [1,2,3,4,5]
// Output: [5,4,3,2,1]

// Example 2
// Input: head = [1,2]
// Output: [2,1]


// Definition for singly-linked list.
struct ListNode 
{
    int val;
    ListNode *next;
    
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
 };
 

class Solution {
public:
    ListNode* reverseList(ListNode* head_) 
    {
        ListNode* newHead;
        
        if (!head_) 
        {
            return 0; 
        }
        
        if (!(head_->next))
        {
            return head_;
        }
        
        newHead = reverseList(head_->next);
        
        (head_->next)->next = head_;
        head_->next = 0;
        
        return newHead;
    }
};                     
                                    
