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
    int k, result;
    void inorder(TreeNode* node) {
        if(node != NULL) {
            inorder(node->left);
            if(--k == 0) {
                result = node->val;
                return;
            }
            inorder(node->right);
        }
    }

    int kSmallest(TreeNode* root, int k) {
        this->k = k;
        this->result = -1;
        inorder(root);
        return result;
    }

public:
	int kthSmallest(TreeNode* root,int k){
		return {kSmallest(root, k)};
	}
};