class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size();
        
        int count = 0;
        int maxiOne = 0;

        for(int i=0;i<n;i++){
            if(nums[i] == 0){
                maxiOne = max(maxiOne , count);
                count = 0;
            }
            else{
                count++;
            } 
        }

        maxiOne = max(maxiOne , count);
        return maxiOne;
    }
};