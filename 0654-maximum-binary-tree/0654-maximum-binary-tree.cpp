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
    TreeNode* maxBinTree(vector<int>&nums, int start, int end){
        if(start == end) {
            return NULL;
        }

        int maxIndex = start;

        for(int i = start + 1; i < end; i++) {
            if(nums[i] > nums[maxIndex]) {
                maxIndex = i;
            }
        }

        TreeNode* root = new TreeNode(nums[maxIndex]);
        root->left = maxBinTree(nums, start, maxIndex);
        root->right = maxBinTree(nums, maxIndex + 1, end);

        return root;
    }

public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums){
        int n = nums.size();

        return maxBinTree(nums, 0, n);
    }
};