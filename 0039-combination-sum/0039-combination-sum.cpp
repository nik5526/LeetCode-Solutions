class Solution {
private:
    void comb(vector<int>& candidates, int target,int n, int idx,vector<int> &diary,vector<vector<int>> &ans, int sum){
        if(idx == n){
            if(sum == target){
                ans.push_back(diary);
            }
            return;
        }
        comb(candidates, target, n, idx+1, diary, ans, sum);
        if(candidates[idx] + sum<=target){
            diary.push_back(candidates[idx]);
            sum = sum + candidates[idx];
            comb(candidates, target, n, idx, diary, ans, sum);
            diary.pop_back();
            sum = sum - candidates[idx];
        }
        return;

    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        int idx = 0;
        vector<int> diary;
        vector<vector<int>> ans;
        int sum = 0;
        comb(candidates, target, n, idx, diary, ans, sum);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna