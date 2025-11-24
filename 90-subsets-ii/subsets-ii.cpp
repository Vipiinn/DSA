class Solution {
public:

    void findSubset(vector<int>& nums , int idx , vector<int>ds , vector<vector<int>>& ans){

        //base case
        ans.push_back(ds);

        for(int i=idx;i<nums.size();i++){
            if(i != idx && nums[i] == nums[i-1]) continue;
            ds.push_back(nums[i]);
            findSubset(nums,i+1,ds,ans);
            ds.pop_back();
        }
       
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        vector<vector<int>>ans;
        vector<int>ds;

        findSubset(nums,0,ds,ans);

        return ans;
    }
};