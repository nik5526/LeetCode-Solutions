class Solution {
private:
    bool canMakeBouquets(const vector<int>& bloomDay, int m, int k, int day) {
        int bouquets = 0;
        int consecutiveFlowers = 0;

        for (int bloom : bloomDay) {
            if (bloom <= day) {
                consecutiveFlowers++;
                if (consecutiveFlowers == k) {
                    bouquets++;
                    consecutiveFlowers = 0; 
                }
            } else {

                consecutiveFlowers = 0;
            }
        }

        return bouquets >= m;
    }

public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();


        if (1LL * m * k > n) return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int result = -1;


        while (low <= high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                result = mid;       
                high = mid - 1;
            } else {
                low = mid + 1;      
            }
        }

        return result;
    }
};