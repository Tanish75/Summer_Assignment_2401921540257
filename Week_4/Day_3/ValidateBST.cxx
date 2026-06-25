/*
Given the root of a binary tree, determine if it is a valid binary search tree (BST).

A valid BST is defined as follows:

The left subtree of a node contains only nodes with keys strictly less than the node's key.
The right subtree of a node contains only nodes with keys strictly greater than the node's key.
Both the left and right subtrees must also be binary search trees.
 

Example 1:
Input: root = [2,1,3]
Output: true
  
Example 2:
Input: root = [5,1,4,null,null,3,6]
Output: false
Explanation: The root node's value is 5 but its right child's value is 4.
 */

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right)
 *         : val(x), left(left), right(right) {}
 * };
 */

class Solution {
public:
    
    // Check if every node lies within the valid range
    bool isValid(TreeNode* node, long long low, long long high) {
        if (node == nullptr)
            return true;

        // Current node must be strictly inside the range
        if (node->val <= low || node->val >= high)
            return false;

        // Left subtree: values < node->val
        // Right subtree: values > node->val
        return isValid(node->left, low, node->val) &&
               isValid(node->right, node->val, high);
    }

    bool isValidBST(TreeNode* root) 
    {
        return isValid(root, LLONG_MIN, LLONG_MAX);
    }
};
