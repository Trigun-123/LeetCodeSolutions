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
class Solution{
private:
    bool validate(TreeNode* node, long min, long max) {
        if(node == NULL)
            return true;
    
        if(node->val >= max || node->val <= min)
            return false;

        bool leftIsValid = validate(node->left, min, node->val);
        bool rightIsValid = validate(node->right, node->val, max);

        return leftIsValid && rightIsValid;
    }

public:
	bool isValidBST(TreeNode* root){
		return validate(root, LONG_MIN, LONG_MAX);
	}
};