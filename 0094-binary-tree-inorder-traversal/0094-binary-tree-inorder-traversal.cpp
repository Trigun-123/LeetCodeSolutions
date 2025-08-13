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
    void recursiveInorder(TreeNode* root, vector<int> &arr) {
        if(root == nullptr)
            return;
    
        recursiveInorder(root->left, arr);
        arr.push_back(root->val);
        recursiveInorder(root->right, arr);
    }

public:
	vector<int> inorderTraversal(TreeNode* root){
	    vector<int> arr;
        recursiveInorder(root, arr);
        return arr;
	}
};