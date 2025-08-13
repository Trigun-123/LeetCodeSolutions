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
    void recursivePreorder(TreeNode* node, vector<int> &arr) {
        if(node == NULL)
            return;

        arr.push_back(node->val);
        recursivePreorder(node->left, arr);
        recursivePreorder(node->right, arr);
    }

public:
	vector<int> preorderTraversal(TreeNode* root){
	    vector<int> arr;
        recursivePreorder(root, arr);
        return arr;
	}
};