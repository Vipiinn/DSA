class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        
        unordered_set<int>st;
        int ans = 0;

        for(int i=0;i<nums.size();i++){
            if(st.find(nums[i]) != st.end()){
                ans = nums[i];
                break;
            }
            st.insert(nums[i]);
        }

        return ans;
    }
};