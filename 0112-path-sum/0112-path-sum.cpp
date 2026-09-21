class Solution {
private:
    void fun(TreeNode* root, int targetSum,int sum,bool &ans){
        if(root == nullptr){
            return;
        }
        sum = sum + root->val;
        if(root->left == nullptr && root->right == nullptr){
            if(sum == targetSum){
                ans = true;
            }
            return;
        }
        fun(root->left,targetSum,sum,ans);
        fun(root->right,targetSum,sum,ans);
        return;
    }
public:
    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = false;
        fun(root,targetSum,0,ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna