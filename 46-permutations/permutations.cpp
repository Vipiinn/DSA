class Solution {
public:

    void permutation(vector<int>& nums,int idx,vector<int>ds,vector<vector<int>>&ans){
        //base case

        if(ds.size() == nums.size()){
            ans.push_back(ds);
            return ;
        }

        for(int i=idx;i<nums.size();i++){
            ds.push_back(nums[i]);
            swap(nums[i],nums[idx]);
            permutation(nums,idx+1,ds,ans);
            swap(nums[i],nums[idx]);
            ds.pop_back();

        }
    }

    vector<vector<int>> permute(vector<int>& nums) {

        vector<vector<int>>ans;
        vector<int>ds;

        permutation(nums,0,ds,ans);

        return ans;
        
    }
};