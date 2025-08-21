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
public:
    void recoverTree(TreeNode* root) {
        TreeNode *first = nullptr, *middle = nullptr, *last = nullptr, *prev = nullptr;
        function<void(TreeNode*)> inorder = [&](TreeNode* node) {
            if(!node)
                return;

            inorder(node->left);
            if(prev && prev->val > node->val) {
                if(!first) {
                    first = prev;  
                    middle = node; 
                }
                else
                    last = node;  
            }
            prev = node;
            inorder(node->right);
        };

        inorder(root);

        if(first && last)
            swap(first->val, last->val);
        else if (first && middle)
            swap(first->val, middle->val);
    }
};