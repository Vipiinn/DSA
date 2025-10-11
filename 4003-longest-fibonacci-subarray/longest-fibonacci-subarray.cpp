class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int ans =  INT_MIN;
        for(int i=2;i<n;i++){
            if(nums[i] == nums[i-1] + nums[i-2]) count++;
            else {
                ans = max(ans,count);
                count = 0;
            }
        }
        ans = max(ans,count);
        return ans+2;
    }
};