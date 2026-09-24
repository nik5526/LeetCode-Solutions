class Solution {
private:
    int fun(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode*& ans) {
        if (root == NULL) {
            return 0;
        }
        int left = fun(root->left, p, q,ans);
        int right = fun(root->right, p, q,ans);
        int self = 0;
        if (root == p || root == q) {
            self++;
        }
        int total = left + self + right;
        if (total == 2 && ans == NULL) {
            ans = root;
        }
        return total;
    }

public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        fun(root, p, q, ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna