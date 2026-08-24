class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i : stones){
            pq.push(i);
        }
        while(!pq.empty()){
            if(pq.size() == 1){
                return pq.top();
            }
            int x = pq.top();
            pq.pop();
            int y = pq.top();
            pq.pop();
            if((x-y) > 0){
                pq.push({x-y});
            }
        }
        return 0;
    }
};