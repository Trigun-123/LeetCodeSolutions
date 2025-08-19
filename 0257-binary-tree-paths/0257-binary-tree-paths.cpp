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
    void findPath(TreeNode* node, vector<string>& result, string temp) {
        temp += to_string(node->val); 
        if(node->left)
            findPath(node->left, result, temp + "->");  
        if(node->right)
            findPath(node->right, result, temp + "->");
        if(!node->left && !node->right)
            result.push_back(temp);
    }

public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        if(root)
            findPath(root, result, ""); 
        return result;
    }
};