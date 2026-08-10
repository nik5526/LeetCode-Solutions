class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> hash;
        int res = 0 ;
        for(int i=0;i<s.size();i++){
            hash[s[i]]++;
        }
        bool odd = false;
        for(auto i : hash){
            int val = i.second;
            if(val%2 == 0){
                res = res + val;
            }
            else{
                odd = true;
                res = res + val-1;
            }
        }
        if(odd){
            return res+1;
        }
        return res;
    }   
};