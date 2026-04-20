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
    int result = 0;

    void preOrder(TreeNode* root, vector<int>& nodes) {
        if(!root) {
            return;
        }   

        nodes.push_back(root->val);
        preOrder(root->left, nodes);
        preOrder(root->right, nodes);
        return;
    }

    void dfs(TreeNode* root) {
        if(!root) {
            return;
        }    

        vector<int> nodes;
        preOrder(root, nodes);
        int sum = accumulate(nodes.begin(), nodes.end(), 0);

        if(root->val == sum/nodes.size()) {
            result++;
        }

        dfs(root->left);
        dfs(root->right);
        return;
    }

public:
    int averageOfSubtree(TreeNode* root) {
        dfs(root);
        return result;
    }
};