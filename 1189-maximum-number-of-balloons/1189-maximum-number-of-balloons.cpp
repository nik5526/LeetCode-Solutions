class Solution {
public:
    int maxNumberOfBalloons(string text) {
        unordered_map<char,int> have;

        for(int i = 0;i<text.size();i++){
            have[text[i]]++;
        }
        unordered_map<char,int> need;
        need['b'] = 1;
        need['a'] = 1;
        need['l'] = 2;
        need['o'] = 2;
        need['n'] = 1;

        int res = INT_MAX;
        for(auto i : need){
            int c = i.first;
            int val_need = i.second;
            int val_have = have[c];
            int diff = val_have/val_need;
            res = min(res,diff);
        }
        return res;
    }
};