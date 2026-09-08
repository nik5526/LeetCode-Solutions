class Solution {
private:
char toLowercase(char lc){
    if((lc>='a' && lc<='z')||(lc>='0' && lc<='9')){
        return lc;
    }
    else{
        char temp = lc-'A'+'a';
        return temp;
    }
}
bool isValid(char lc){
    if((lc>='a' && lc<='z')||(lc>='A' && lc<='Z')||(lc>='0' && lc<='9')){
        return 1;
    }
    else{
        return 0;
    }
}
bool checkPalindrome(string pal){
    int s=0;
    int e=pal.size()-1;
    while(s<=e){
        if(pal[s]!=pal[e]){
            return 0;
        }
        else{
            s++;
            e--;
        }
        
    }
    return 1;
}

public:
    bool isPalindrome(string s) {
        string temp = "";
        for(int i=0;i<s.size();i++){
            if(isValid(s[i])){
                temp.push_back(s[i]);
            }
        }

        for(int i=0;i<temp.size();i++){
            temp[i] = toLowercase(temp[i]);
        }

        return checkPalindrome(temp);
    }
};