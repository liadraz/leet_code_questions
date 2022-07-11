// Question
// -------------------------------------------------------------------------- //

// Given the root of a binary tree, return its maximum depth.

// A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.

// Input: root = [3,9,20,null,null,15,7]
// Output: 3
// Example 2:

// Input: root = [1,null,2]
// Output: 2

// Constraints:

// The number of nodes in the tree is in the range [0, 104].
// -100 <= Node.val <= 100


// Definition for a binary tree node.
 struct TreeNode 
 {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
 };



int maxDepth(struct TreeNode* root)
{
    // base case
    if (0 == root)
    {
        return 0;
    }
    
    int left_ctr = maxDepth(root->left);
    int right_ctr = maxDepth(root->right);
    
    if (left_ctr > right_ctr)
    {
        return 1 +  left_ctr;
    }
    else
    {
        return 1 +  right_ctr;
    }
}