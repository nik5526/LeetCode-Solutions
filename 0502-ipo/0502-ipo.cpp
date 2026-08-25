class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        int n = profits.size();
        vector<pair<int,int>> res;
        for(int i = 0;i<n;i++ ){
            res.push_back({capital[i],profits[i]});
        }
        sort(res.begin(),res.end());
        priority_queue<int> pq;
        int inx = 0;
        while(k--){
            while(inx < n){
                if(res[inx].first>w){
                    break;
                }
                pq.push(res[inx].second);
                inx++;
            }
            if(pq.empty()){
                return w;
            }
            w += pq.top();
            pq.pop();
        }
        return w;
    }
};