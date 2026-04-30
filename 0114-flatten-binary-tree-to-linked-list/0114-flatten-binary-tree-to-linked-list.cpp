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
    TreeNode* solve(TreeNode* root) {
        while(root->right) {
            root = root->right;
        }
        
        return root;
    }

public:
    void flatten(TreeNode* root) {
        if(root == NULL) {
            return;
        }    

        flatten(root->left);
        flatten(root->right);

        if(root->left) {
            TreeNode* leftEnd = solve(root->left);
            leftEnd->right = root->right;
            root->right = root->left;
            root->left = NULL;
        }
    }
};