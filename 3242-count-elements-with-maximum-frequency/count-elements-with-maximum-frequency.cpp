class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int>m;

        for(int i=0;i<nums.size();i++){
            m[nums[i]]++;
        }

        int maxfreq = INT_MIN;

        for(auto x : m){
            int ele = x.second;
            maxfreq = max(maxfreq , ele);
        }

        int ans = 0;

        for(auto x : m){
            if(x.second == maxfreq) ans += maxfreq;
        }

        return ans;
    }
};