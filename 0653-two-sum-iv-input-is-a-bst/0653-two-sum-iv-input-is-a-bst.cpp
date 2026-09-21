class Solution {
public:
stack<TreeNode*> asc;
stack<TreeNode*> dec;
int getSmall(){
    
    TreeNode* small = asc.top();
    asc.pop();
    TreeNode* right = small->right;
    while(right){
        asc.push(right);
        right = right->left;
    }
    return small->val;
}

int getBig(){
    
    TreeNode* big = dec.top();
    dec.pop();
    TreeNode* left = big->left;
    while(left){
        dec.push(left);
        left = left->right;
    }
    return big->val;
}

    bool findTarget(TreeNode* root, int k) {
        if(root == nullptr){
            return false;
        }
        TreeNode* t = root;
        while(t){
            asc.push(t);
            t = t->left;
        }
        t = root;
        while(t){
            dec.push(t);
            t = t->right;
        }
        int i = getSmall();
        int j = getBig();

        while(i<j){
            int sum = i+j;
            if(sum == k){
                return true;
            }
            else if(sum < k){
                i = getSmall();
            }
            else{
                j = getBig();
            }
        }
        return false;
        
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna