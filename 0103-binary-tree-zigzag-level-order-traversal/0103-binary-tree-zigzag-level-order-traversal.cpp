class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        queue<TreeNode*> q;
        q.push(root);
        vector<vector<int>> ans;
        int left = 1;
        while(!q.empty()){
            int lvlSize = q.size();
            int start = 0;
            int end = lvlSize-1;
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
            if(left == 1){
                ans.push_back(temp);
                left = 1-left;
            }
            else{
                reverse(temp.begin(),temp.end());
                ans.push_back(temp);
                left = 1-left;
            }
        }
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna