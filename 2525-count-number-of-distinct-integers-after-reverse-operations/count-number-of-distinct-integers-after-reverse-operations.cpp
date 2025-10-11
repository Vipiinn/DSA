class Solution {
public:

    void reverseAndAdd(int n , unordered_set<int>& s){
        
        s.insert(n);
        int ans = 0;
        while(n > 0){
            int digit = n%10;
            ans = ans*10 + digit;
            n /= 10;
        }
        s.insert(ans); 
    }

    int countDistinctIntegers(vector<int>& nums) {

        unordered_set<int> s;

        for(int i=0;i<nums.size();i++){
            reverseAndAdd(nums[i] , s);
        }

        return s.size();
    }
};