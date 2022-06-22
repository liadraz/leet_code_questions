
// Question
// -------------------------------------------------------------------------- //

// Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

// A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.


// Example 1
// Input: nums = [-10,-3,0,5,9]
// Output: [0,-3,9,-10,null,5]
// Explanation: [0,-10,5,null,-3,null,9] is also accepted:

// Example 2
// Input: nums = [1,3]
// Output: [3,1]
// Explanation: [1,null,3] and [3,1] are both height-balanced BSTs.


#include <stdio.h>

// Definition for a binary tree node.
struct TreeNode 
{
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
};

struct TreeNode *CreateSubTree(int *nums_, int left_, int right_);



struct TreeNode* sortedArrayToBST(int* nums, int numsSize)
{
    assert(nums != NULL);
    
    return CreateSubTree(nums, 0, numsSize - 1);
}


struct TreeNode *CreateSubTree(int *nums_, int left_, int right_)
{
    struct TreeNode *root = NULL;
    int mid = 0;
    
    if (left_ > right_)
    {
        return NULL;
    }
    
    mid = (left_ + right_) / 2;
    
    root = (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = nums_[mid];
    root->left = NULL;
    root->right = NULL;
    
    root->left = CreateSubTree(nums_, left_, mid - 1);
    root->right = CreateSubTree(nums_, mid + 1, right_);
    
    return root;
}
