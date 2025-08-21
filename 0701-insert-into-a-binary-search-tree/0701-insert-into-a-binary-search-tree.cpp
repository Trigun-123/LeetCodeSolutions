/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
private:    
    TreeNode* solve(TreeNode* node, int val) {
        if(node == NULL)
            return new TreeNode(val);
        
        if(val < node->val)
            node->left = solve(node->left, val);
        else
            node->right = solve(node->right, val);

        return node;
    }

public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        return solve(root, val);
    }
};