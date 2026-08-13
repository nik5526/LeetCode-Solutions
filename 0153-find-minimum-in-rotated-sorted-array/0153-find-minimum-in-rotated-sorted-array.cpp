class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int n = nums.size();
        int h = n-1;
        int res = -1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m]>nums[n-1]){
                l = m+1;
            }
            else{
                res = m;
                h = m-1;
            }
        }
        return nums[res];
    }
};