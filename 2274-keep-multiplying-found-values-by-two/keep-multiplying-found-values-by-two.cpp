class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        unordered_set<int> s;
        for(int i=0;i<nums.size();i++){
            s.insert(nums[i]);
        }

        for(auto x : s){
            if(s.find(original) == s.end()) return original;
            else{
                original *= 2;
            }
        }
        return original;
    }
};