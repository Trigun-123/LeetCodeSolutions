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
    int prev = -1, result = INT_MAX;

    void solve(TreeNode* root) {
        if(root == NULL) {
            return;
        }

        solve(root->left);

        if(prev != -1) {
            result = min(result, root->val - prev);
        }

        prev = root->val;
        solve(root->right);
    }

public:
    int getMinimumDifference(TreeNode* root) {
        solve(root);

        return result;
    }
};