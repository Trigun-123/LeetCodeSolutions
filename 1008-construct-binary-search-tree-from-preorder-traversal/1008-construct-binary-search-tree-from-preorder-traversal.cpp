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
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int bound, int& index) {
        if(index == preorder.size() || preorder[index] > bound)
            return 0;

        TreeNode* root = new TreeNode(preorder[index++]);
        root->left = bstFromPreorderHelper(preorder, root->val, index);
        root->right = bstFromPreorderHelper(preorder, bound, index);

        return root;
    }
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int index = 0;
        return bstFromPreorderHelper(preorder, INT_MAX, index);
    }
};