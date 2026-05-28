class Solution {
public:

    int lowerBound(vector<int>& nums , int target){

        int idx = -1;
        int st = 0;
        int end = nums.size() - 1;

        while(st <= end){
            int mid = st + (end-st) / 2;

            if(nums[mid] == target){
                idx = mid;
                end = mid - 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return idx;
    }

    int upperBound(vector<int>& nums , int target){

        int idx = -1;
        int st = 0;
        int end = nums.size() - 1;

        while(st <= end){
            int mid = st + (end-st) / 2;

            if(nums[mid] == target){
                idx = mid;
                st = mid + 1;
            }
            else if(nums[mid] > target){
                end = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }

        return idx;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        
        int lb = lowerBound(nums , target);
        int ub = upperBound(nums , target);

        return {lb , ub};
    }
};