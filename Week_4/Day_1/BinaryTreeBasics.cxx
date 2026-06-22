
/*Given the root of a binary tree, return its maximum depth.

A binary tree's maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Example 1:
Input: root = [3,9,20,null,null,15,7]
Output: 3
Example 2:

Input: root = [1,null,2]
Output: 2
 */







class Solution {
public:
    int maxDepth(TreeNode* root) 
 {
        // Base case: if the node is null, depth is 0
        if (root == nullptr) 
            return 0;
          
        
        // Recursively find the depth of left and right subtrees
        int leftDepth = maxDepth(root->left);
        int rightDepth = maxDepth(root->right);
        
        // The total depth is 1 (current node) + the maximum of the two sides
        return 1 + std::max(leftDepth, rightDepth);
    }
};
