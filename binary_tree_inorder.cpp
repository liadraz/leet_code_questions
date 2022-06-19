
// Question
// -------------------------------------------------------------------------- //

// Given the root of a binary tree, return the inorder traversal of its nodes' values.

// Example
// Input: root = [1,null,2,3]
// Output: [1,3,2]


// Definition for a binary tree node.
struct TreeNode 
{
int val;
TreeNode *left;
TreeNode *right;
 
TreeNode() : val(0), left(nullptr), right(nullptr) {}
TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


#include <vector>

class Solution 
{
public:
    std::vector<int> inorderTraversal(TreeNode* root) 
    {
        std::vector<int> nodes;
        
        InOrder(root, nodes);
        
        return nodes;
    }
    
private:
    void InOrder(TreeNode* node_, std::vector<int>& nodes_)
    {
        if (node_ == 0)
        {
            return;
        }
        
        InOrder(node_->left, nodes_);
        nodes_.push_back(node_->val);
        InOrder(node_->right, nodes_);
    }
};

