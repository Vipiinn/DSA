class Solution {
public:
    bool checkIfPangram(string sentence) {

        int n = sentence.length();

        vector<int>arr(26,0);

        for(int i=0;i<n;i++){
            int idx = sentence[i] - 'a';
            arr[idx]++;
        }

        for(int i=0;i<26;i++){
            if(arr[i] == 0) return false;
        }

        return true;
    }
};