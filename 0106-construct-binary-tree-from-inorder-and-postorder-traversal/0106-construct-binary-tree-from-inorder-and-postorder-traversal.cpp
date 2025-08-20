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
    TreeNode* buildBTree(vector<int>& postorder, int postStart, int postEnd, vector<int>& inorder, int inStart, int inEnd, unordered_map<int, int>& map) {
        if(inStart > inEnd || postStart > postEnd)
            return NULL;

        int rootValue = postorder[postEnd];
        TreeNode* root = new TreeNode(rootValue);

        int rootIndexInorder = map[rootValue];
        int leftSubtreeSize = rootIndexInorder - inStart;

        root->left = buildBTree(postorder, postStart, postStart+leftSubtreeSize-1, inorder, inStart, rootIndexInorder-1, map);
        root->right = buildBTree(postorder, postStart+leftSubtreeSize,postEnd-1, inorder, rootIndexInorder+1, inEnd, map);
        return root;
    }

public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        int n = inorder.size();
        int m = postorder.size();

        if(inorder.empty() || postorder.empty()  || inorder.size() != postorder.size())
            return 0;

        unordered_map<int, int> map;
        for(int i = 0; i < n; i++)
            map[inorder[i]] = i;

        return buildBTree(postorder, 0, n-1, inorder, 0, m, map);
    }
};