class Solution {
private:
    bool fun(TreeNode* left,TreeNode* right){
        if(left == nullptr && right == nullptr){
            return true;
        }
        if(left == nullptr || right == nullptr){
            return false;
        }
        if(left->val != right->val){
            return false;
        }
        bool a = fun(left->left,right->right);
        bool b = fun(left->right,right->left);
        return a&b;
    }
public:
    bool isSymmetric(TreeNode* root) {
        return fun(root->left,root->right);
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna