/*
Given the root of a binary tree, check whether it is a mirror of itself (i.e., symmetric around its center).
Example 1:
Input: root = [1,2,2,3,4,4,3]
Output: true
Example 2:
Input: root = [1,2,2,null,3,null,3]
Output: false
 */


class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) 
    {
        // If both NULL
        if (left == NULL && right == NULL)
            return true;

        // If only one NULL
        if (left == NULL || right == NULL)
            return false;

        // Values should  equal
        if (left->val != right->val)
            return false;

        // Check mirror condition
        return check(left->left, right->right) &&
               check(left->right, right->left);
    }

    bool isSymmetric(TreeNode* root) 
    {
        if (root == NULL)
            return true;

        return check(root->left, root->right);
    }
};
