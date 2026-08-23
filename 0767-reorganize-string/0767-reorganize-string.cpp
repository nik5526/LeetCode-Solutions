class Solution {
public:
    string reorganizeString(string s) {
        unordered_map<char,int> hash;
        for(auto i : s){
            hash[i]++;
        }

        priority_queue<pair<int, char>> pq;
        for(auto i : hash){
            char ele = i.first;
            int freq = i.second;
            pair<int,char> curr = {freq,ele};
            pq.push(curr);
        }

        string res ="";
        int pos = 0;
        while(!pq.empty()){
            pair<int ,char> p = pq.top();
            pq.pop();
            if(pos == 0 || res[pos-1] != p.second){
                res.push_back(p.second);
                pos++;
                p.first--;
                if(p.first>0){
                    pq.push(p);
                }
            }
            else{
                if(pq.empty()){
                    return "";
                }
                pair<int,char> p2 = pq.top();
                pq.pop();
                res.push_back(p2.second);
                pos++;
                p2.first--;
                if(p2.first>0){
                    pq.push(p2);
                }
                pq.push(p);
            }
        }
        return res;
    }
};