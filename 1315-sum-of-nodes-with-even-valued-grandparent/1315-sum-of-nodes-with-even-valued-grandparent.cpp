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
    int solve(TreeNode* current, int parent, int grandParent) {
        if(current == NULL) {
            return 0;
        }

        return solve(current->left, current->val, parent) + solve(current->right, current->val, parent) + (grandParent%2==0 ? current->val:0);
    }

public:
    int sumEvenGrandparent(TreeNode* root) {
        return solve(root, 1, 1);
    }
};