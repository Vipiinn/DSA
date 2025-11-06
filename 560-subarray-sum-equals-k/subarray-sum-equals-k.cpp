class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        
        vector<int> pre(n);
        pre[0] = nums[0];

        for(int i=1;i<n;i++){
            pre[i] = pre[i-1] + nums[i];
        }

        unordered_map<int,int>m;

        int count = 0;

        for(int i=0;i<n;i++){
            if(pre[i] == k) count++;
            int rem = pre[i] - k;
            if(m.find(rem) != m.end()){
                count += m[rem];
            }
            m[pre[i]]++;
        }

        return count;

    }
};