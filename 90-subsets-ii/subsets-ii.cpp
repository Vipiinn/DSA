class Solution {
public:

    void SubsetSum(vector<int>& nums , int idx , vector<int>ds , set<vector<int>>& ans){

        //base case
        if(idx == nums.size()){
            ans.insert(ds);

            return;
        }

        ds.push_back(nums[idx]);
        SubsetSum(nums,idx+1,ds,ans);
        ds.pop_back();
        SubsetSum(nums,idx+1,ds,ans);

       
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin() , nums.end());

        set<vector<int>>ans;
        vector<int>ds;

        SubsetSum(nums,0,ds,ans);

        return vector<vector<int>>(ans.begin() , ans.end());
    }
};