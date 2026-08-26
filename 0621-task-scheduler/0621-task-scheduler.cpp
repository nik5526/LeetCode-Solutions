using namespace std;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> hash;
        for (char t : tasks) {
            hash[t]++;
        }

        priority_queue<int> pq;
        for (auto& [task, count] : hash) {
            pq.push(count);
        }

        int totalTime = 0;
        while (!pq.empty()) {
            int cycle = n + 1;
            vector<int> waitList;
            int tasksExecuted = 0;
            while (cycle > 0 && !pq.empty()) {
                int currentFreq = pq.top();
                pq.pop();

                if (--currentFreq > 0) {
                    waitList.push_back(currentFreq);
                }

                tasksExecuted++;
                cycle--;
            }
            for (int remainingFreq : waitList) {
                pq.push(remainingFreq);
            }
            totalTime += pq.empty() ? tasksExecuted : (n + 1);
        }

        return totalTime;
    }
};