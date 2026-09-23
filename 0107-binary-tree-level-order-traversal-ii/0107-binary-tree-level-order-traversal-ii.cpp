class Solution {
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        queue<TreeNode* > q;
        q.push(root);
        vector<vector<int>> ans;
        while(!q.empty()){
            int lvlSize = q.size();
            vector<int> temp;
            while(lvlSize--){
                TreeNode* t = q.front();
                q.pop();
                temp.push_back(t->val);
                if(t->left != nullptr){
                    q.push(t->left);
                }
                if(t->right != nullptr){
                    q.push(t->right);
                }
            }
            ans.push_back(temp);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna