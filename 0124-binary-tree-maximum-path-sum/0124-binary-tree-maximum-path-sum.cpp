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
    int findMaxPathSum(TreeNode* root, int& maxx) {
        if(root == NULL)
            return 0;

        int leftPath = max(0, findMaxPathSum(root->left, maxx));
        int rightPath = max(0, findMaxPathSum(root->right, maxx));

        maxx = max(maxx, leftPath + rightPath + root->val);

        return max(leftPath, rightPath) + root->val;
    }    

public:
    int maxPathSum(TreeNode* root) {
        int maxx = INT_MIN;
        findMaxPathSum(root, maxx);
        return maxx;
    }
};	