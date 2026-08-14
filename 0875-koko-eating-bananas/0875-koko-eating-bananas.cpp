long long func(vector<int>& a, int speed){
    int n = a.size();
    long long hr = 0;
    for(int i =0; i<n;i++){
        hr = hr + a[i]/speed;
        if(a[i] %speed != 0) hr++;
    }
    return hr;
}
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        int n = piles.size();
        for(int i = 0;i<n;i++){
            high = max(high,piles[i]);
        } 
        int res = -1;
        while(low<=high){
            int m = low + (high-low)/2;
            long long hrs = func(piles,m);
            if(hrs > h){
                low = m+1;
            }
            else{
                res = m;
                high = m-1;
            }
        }
        return res;
    }
};