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
    int depthFirstSearch(TreeNode* currentNode, int currentValue) {
        if(currentNode == NULL) {
            return 0;
        }    

        currentValue = currentValue * 2 + currentNode->val;

        if(currentNode->left == NULL && currentNode->right == NULL) {
            return currentValue;
        }    

        return depthFirstSearch(currentNode->left, currentValue) +
               depthFirstSearch(currentNode->right, currentValue);
    }

public:
    int sumRootToLeaf(TreeNode* rootNode) {
        return depthFirstSearch(rootNode, 0);
    }
};