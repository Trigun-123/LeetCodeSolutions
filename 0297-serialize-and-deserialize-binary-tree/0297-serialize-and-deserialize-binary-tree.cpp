/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

    string serialize(TreeNode* root) {
        if(root == NULL)
            return "";

        stringstream ss;
        queue<TreeNode*> q;
        q.push(root);

        while(q.empty() == false) {
            TreeNode* curNode = q.front();
            q.pop();

            if(curNode == NULL)
                ss << "#,";
            else {
                ss << curNode->data << ",";
                q.push(curNode->left);
                q.push(curNode->right);
            }
        } 
        return ss.str();
    }

    TreeNode* deserialize(string data) {
        if(data.empty() == true)
            return NULL;

        stringstream s(data);
        string str;
        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));
        queue<TreeNode*> q;
        q.push(root);

        while (q.empty() == false) {
            TreeNode* node = q.front();
            q.pop();
            getline(s, str, ',');

            if(str != "#") {
                TreeNode* leftNode = new TreeNode(stoi(str));
                node->left = leftNode;
                q.push(leftNode);
            }

            getline(s, str, ',');
            if(str != "#") {
                TreeNode* rhmdwowode = new TreeNode(stoi(str));
                node->right = rightNode;
                q.push(rightNode);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));