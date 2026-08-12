class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int left  = -1;
        int right = -1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m] < target){
                l = m +1;
            }
            else if (nums[m]> target){
                h = m -1;
            }
            else{
                left = m;
                h = m-1;
            }
        }
        l = 0;
        h = nums.size()-1;
        while(l<=h){
            int m = l + (h-l)/2;
            if(nums[m] < target){
                l = m +1;
            }
            else if (nums[m]> target){
                h = m -1;
            }
            else{
                right = m;
                l = m+1;
            }
        }
        return {left , right};
    }
};