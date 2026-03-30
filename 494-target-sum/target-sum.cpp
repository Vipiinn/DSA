class Solution {
public:

    void countSubsetSum(vector<int>& arr , int sum , vector<vector<int>>& dp){

        int n = arr.size();

        for(int i=1;i<=n;i++){
            for(int j=0;j<=sum;j++){

                if(arr[i-1] <= j){
                    dp[i][j] = dp[i-1][j-arr[i-1]] + dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        
        int n = nums.size();
        
        int arrSum = 0;
        for(int i=0;i<n;i++){
            arrSum += nums[i];
        }

        if(arrSum < abs(target) || (arrSum + target) % 2 != 0) return 0;

        int sum = (arrSum + target) / 2;

        vector<vector<int>>dp(n+1 , vector<int>(sum+1));

        for(int i=0;i<=n;i++){
            for(int j=0;j<=sum;j++){
                if(i == 0) dp[i][j] = 0;
                if(j == 0) dp[i][j] = 1;
            }
        }

        countSubsetSum(nums,sum , dp);

        return dp[n][sum];

    }
};