class Solution {
public:
    std::string reorganizeString(std::string s) {
        int n = s.length();
        std::vector<int> freq(26, 0);
        

        for (char c : s) {
            freq[c - 'a']++;
        }
        

        int maxFreq = 0;
        char maxChar = ' ';
        for (int i = 0; i < 26; i++) {
            if (freq[i] > maxFreq) {
                maxFreq = freq[i];
                maxChar = (char)('a' + i);
            }
        }
        

        if (maxFreq > (n + 1) / 2) {
            return "";
        }
        
        std::string result(n, ' ');
        int index = 0;
        

        while (freq[maxChar - 'a'] > 0) {
            result[index] = maxChar;
            index += 2;
            freq[maxChar - 'a']--;
        }
        
        
        for (int i = 0; i < 26; i++) {
            while (freq[i] > 0) {
                if (index >= n) {
                    index = 1; 
                }
                result[index] = (char)('a' + i);
                index += 2;
                freq[i]--;
            }
        }
        
        return result;
    }
};