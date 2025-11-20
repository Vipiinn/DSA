class Solution {
public:

    void combination(vector<int>& candidates,int idx, int target , vector<int>output , vector<vector<int>>& ans){

        //base case
        if(idx == candidates.size()){
            if(target == 0){
                ans.push_back(output);
            }
            return;
        }
        if(candidates[idx] <= target){
            output.push_back(candidates[idx]);
            combination(candidates,idx,target-candidates[idx],output,ans);
            output.pop_back();
        }

        combination(candidates,idx+1,target,output,ans);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {

        vector<vector<int >> ans;
        vector<int>output;

        combination(candidates,0,target,output,ans);

        return ans;
        
    }
};