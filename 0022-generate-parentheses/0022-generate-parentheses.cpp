class Solution {
    private:
    void gen(int n, int open,int close,string str,vector<string> &ans){
        if(open == n && close == n){
            ans.push_back(str);
            return;
        }

        if(open<n){
            str.push_back('(');
            gen(n,open+1,close,str,ans);
            str.pop_back();
        }
        if(close<open){
            str.push_back(')');
            gen(n,open,close+1,str,ans);
            str.pop_back();
        }  
    }
public:
    vector<string> generateParenthesis(int n) {
        int open = 0;
        int close = 0;
        string str = "";
        vector<string> ans;
        gen(n,open,close,str,ans);
        return ans;
    }
};

// Synced seamlessly with LeetHub Pro
// Pro features: https://bit.ly/leethubpro | Free version: https://bit.ly/leethubv4
// Get it here: https://chromewebstore.google.com/detail/bcilpkkbokcopmabingnndookdogmbna