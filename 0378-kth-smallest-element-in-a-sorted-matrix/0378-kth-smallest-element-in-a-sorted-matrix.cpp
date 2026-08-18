int fun(vector<vector<int>>& a,int m,int n,long long mid){
    int row = m-1;
    int col = 0;

    int cnt = 0;
    while(row >=0 && col < n){
        if(a[row][col] <= mid){
            cnt += (row+1);
            col++;
        }
        else{
            row--;
        }
    }
    return cnt;

}

class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
    
        int l = matrix[0][0];
        int h = matrix[m-1][n-1];
        int res = -1;

        while(l<=h){
            int mid = l+(h-l)/2;
            int cnt = fun(matrix,m,n,mid);
            if(cnt >= k){
                res = mid;
                h = mid-1;
            }
            else{
                l = mid+1;
            }
        }
        return res;

    }
};