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
    void recursivePostorder(TreeNode* root, vector<int>& arr) {
        if(root == NULL)
            return;
        
        recursivePostorder(root->left, arr);
        recursivePostorder(root->right, arr);
        arr.push_back(root->val);
    }

public:
	vector<int> postorderTraversal(TreeNode* root){
	    vector<int> arr;
        recursivePostorder(root, arr);
        return arr;
	}
};