class Solution {
private:
    void fun(TreeNode*& root){
        if(root == nullptr){
            return;
        }
        swap(root->left,root->right);
        fun(root->left);
        fun(root->right);
        return;
    }
public:
    TreeNode* invertTree(TreeNode* root) {
        fun(root);
        return root;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna