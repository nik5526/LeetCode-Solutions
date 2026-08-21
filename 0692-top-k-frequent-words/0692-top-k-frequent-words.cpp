class Solution {
    struct cpm{
        bool operator()(pair<int,string>&a,pair<int,string>&b){
            if(a.first != b.first){
                return a.first>b.first;
            }
            return a.second<b.second;
        }
    };
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        priority_queue<pair<int,string>,vector<pair<int,string>>,cpm> pq;
        vector<string> res;
        unordered_map<string,int>hash;
        for(auto i : words){
            hash[i]++;
        }
        for(auto i : hash){
            string ele = i.first;
            int freq = i.second;
            pair<int,string> curr = {freq,ele};
            pq.push(curr);
            if(pq.size()>k){
                pq.pop();
            }
        }
        while(!pq.empty()){
            res.push_back(pq.top().second);
            pq.pop();
        }
        reverse(res.begin(),res.end());
        return res;
    }
};