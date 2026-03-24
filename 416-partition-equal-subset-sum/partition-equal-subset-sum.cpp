// using top down

class Solution {
public:


    bool isPossible(vector<int>&nums , int sum , int n , vector<vector<int>>& dp){

        //base case
        if(sum == 0) return true;
        if(n <= 0) return false;

        if(dp[n][sum] != -1){
            return dp[n][sum];
        }

        if(nums[n-1] <= sum){
            return dp[n][sum] =  isPossible(nums,sum-nums[n-1],n-1,dp) || isPossible(nums,sum,n-1,dp);
        }
        else return dp[n][sum] =  isPossible(nums,sum,n-1,dp);
    }

    bool canPartition(vector<int>& nums) {
        
        int n = nums.size();
        int sum = 0;

        for(int i=0;i<n;i++){
            sum += nums[i];
        }

        //check even or odd
        if(sum % 2 != 0) return false;

        sum = sum / 2;

        // now the question is coverted in subset problem

        vector<vector<int>>dp(n+1,vector<int>(sum+1 , -1));


        return isPossible(nums,sum,n,dp);
        
    }
};