class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
        
        string ans = "";
        unordered_map<string,int>mp;

        for(auto ele : arr){
            mp[ele]++;
        }

        for(int i=0;i<arr.size();i++){
            if(mp[arr[i]] == 1){
                k--;
                if(k==0) ans = arr[i];
            }
        }
        return ans;
    }
};