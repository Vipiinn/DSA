class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int>ans;
        int st = 0;
        int end = nums.size()-1;

        while(st < end){
            if(nums[st] + nums[end] == target){
                ans.push_back(st + 1);
                ans.push_back(end + 1);
                return ans;
            }
            else if(nums[st] + nums[end] > target){
                end--;
            }
            else st++;
        }

        return ans;
    }
};