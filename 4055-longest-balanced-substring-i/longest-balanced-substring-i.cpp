class Solution {
private:
    bool checkBalanced(const unordered_map<char, int>& freq) {
        if (freq.empty()) {
            return false;
        }

        int required_count = -1;
        for (auto const& pair : freq) {
            if (required_count == -1) {
                required_count = pair.second;
            } else if (pair.second != required_count) {
                return false;
            }
        }
        return true;
    }

public:
    int longestBalanced(string s) {
        string temp = s; 
        
        int n = temp.size();
        int maxLength = 0;

        for (int i = 0; i < n; ++i) {
            unordered_map<char, int> freq;
            
            for (int j = i; j < n; ++j) {
                
                freq[temp[j]]++;
                
                if (checkBalanced(freq)) {
                    maxLength = max(maxLength, j - i + 1);
                }
            }
        }

        return maxLength;
    }
};