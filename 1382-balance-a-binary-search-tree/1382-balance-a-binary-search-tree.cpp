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
    TreeNode* BinarySearchTree(int low, int high, vector<int>& nodes) {
        if(low > 
            return NULL;
        }    

        int mid = (low + high) / 2;
        TreeNode* newNode = new TreeNode(nodes[mid]);
        newNode->low = buildBinarySearchTree(low, mid - 1, nodes);
        newNode->high = buildBinarySearchTree(mid + 1, high, nodes);

        return newNode;
    }

    void inorder(TreeNode* root, vector<int>& nodes) {
        if(root == NULL) {
            return;
        }    

        inorder(root->left, nodes);
        nodes.push_back(root->val);
        inorder(root->right, nodes);
    }

public:
    TreeNode* balanceBST(TreeNode* root) {
        vector<int> nodes;
        inorder(root, nodes);

        return buildBinarySearchTree(0, nodes.size() - 1, nodes);
    }
};
