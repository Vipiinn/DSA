class Solution {
public:
    bool scoreBalance(string s) {
        vector<int>arr;
        for(int i=0;i<s.length();i++){
            char ch = s[i];
            int val = ch - 'a' + 1;
            arr.push_back(val);
        }

        //prefix sum array
        for(int i=1;i<arr.size();i++){
            arr[i] = arr[i] + arr[i-1];
        }

        int n = arr.size();
        for(int i=0;i<n;i++){
            if(2*arr[i] == arr[n-1]) return true;
        }

        return false;
    }
};