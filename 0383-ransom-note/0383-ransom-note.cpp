bool fun(unordered_map<char,int> need,unordered_map<char,int> have){
    for(auto i : need){
        char c = i.first;
        int freq_need = i.second;
        int freq_have = have[c];
        if(freq_need > freq_have){
            return false;
        }
    }
    return true;
}

class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char,int> ran;
        unordered_map<char,int> mag;
        for(int i =0 ;i<ransomNote.size() ; i++){
            ran[ransomNote[i]]++;
        }
        for(int i=0;i<magazine.size();i++){
            mag[magazine[i]]++;
        }
        return fun(ran,mag);
    }
};