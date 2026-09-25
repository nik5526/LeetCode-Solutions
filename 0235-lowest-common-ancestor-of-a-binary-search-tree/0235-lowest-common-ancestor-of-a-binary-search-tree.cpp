class Solution {
private:
    void fun(TreeNode* root, TreeNode* p, TreeNode* q,TreeNode*& ans){
        if(root == NULL){
            return;
        }
        if(root == p || root == q){
            ans = root;
            return;
        }
        if(root->val < p->val){
            fun(root->right,p,q,ans);
        }
        else if(root->val > q->val){
            fun(root->left,p,q,ans);
        }
        else{
            ans = root;
            return;
        }
    }
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* ans = NULL;
        if(p->val < q->val){
            fun(root, p, q, ans);
        }
        else{
            fun(root, q , p ,ans);
        }
        
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna