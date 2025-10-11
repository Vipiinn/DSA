class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0;
        int j = 1;
        int k = 2;
        int count = 0;
        int ans =  INT_MIN;

        while(k != n){
            if(nums[i]+nums[j] == nums[k]) count++;
            else{
                ans = max(ans,count);
                count = 0;
            }
            i++;
            j++;
            k++;
        }
        ans = max(ans,count);
        return ans+2;
    }
};