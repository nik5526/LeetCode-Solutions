class Solution {
private:
    void comb(string digits,unordered_map<char,string> &hash,int n,int idx,string &diary,vector<string> &ans){
        if(idx == n){
            ans.push_back(diary);
            return;
        }

        string choice = hash[digits[idx]];
        for(int j = 0;j<choice.size();j++){
            diary.push_back(choice[j]);
            comb(digits,hash,n,idx+1,diary,ans);
            diary.pop_back();
        }
        return;
    }
    
public:
    vector<string> letterCombinations(string digits) {
        unordered_map<char,string> hash;
        hash['0'] = "";
        hash['1'] = "";
        hash['2'] = "abc";
        hash['3'] = "def";
        hash['4'] = "ghi";
        hash['5'] = "jkl";
        hash['6'] = "mno";
        hash['7'] = "pqrs";
        hash['8'] = "tuv";
        hash['9'] = "wxyz";
        int n = digits.length();
        string diary = "";
        vector<string> ans;
        int idx = 0;
        comb(digits,hash,n,idx,diary,ans);

        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna