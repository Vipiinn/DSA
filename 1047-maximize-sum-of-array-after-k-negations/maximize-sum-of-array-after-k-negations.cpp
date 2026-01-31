class Solution {
public:
    int largestSumAfterKNegations(vector<int>& nums, int k) {
        
        //pushing all ele in pq
        priority_queue<int,vector<int>,greater<int>>pq(nums.begin(),nums.end());
        
        while(k > 0){
            int mini = pq.top();
            pq.pop();
            mini *= -1;
            pq.push(mini);
            k--;
        }
        int sum = 0;
        while(pq.size() > 0){
            sum += pq.top();
            pq.pop();
        }

        return sum;
    }
};