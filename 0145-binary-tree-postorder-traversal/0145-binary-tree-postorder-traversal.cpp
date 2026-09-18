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
        void post(TreeNode* root,vector<int> &temp){
            if(root == nullptr){
                return;
            }
            post(root->left,temp);
            post(root->right,temp);
            temp.push_back(root->val);
            return ;
        }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> temp;
        post(root,temp);
        return temp;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna