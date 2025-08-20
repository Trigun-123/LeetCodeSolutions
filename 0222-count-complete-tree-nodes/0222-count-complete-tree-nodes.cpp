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
    int findLeftHeight(TreeNode* node, int height) {
        while(node) {
            height++;
            node = node->left;
        }
        return height;
    }

    int findRightHeight(TreeNode* node, int height) {
        while(node) {
            height++;
            node = node->right;
        }
        return height;
    }

public:
    int countNodes(TreeNode* root) { 
        if(root == NULL)
            return 0;
        
        int height = 0;
        int leftHeight = findLeftHeight(root, height);
        int rightHeight = findRightHeight(root, height);

        if(leftHeight == rightHeight)
            return (1 << leftHeight) - 1;

        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};