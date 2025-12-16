class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        int n = prices.size();
        long long count = n;

        int i = 0;
        long long cnt = 0;
        for(int i=0;i<n-1;i++){
            if(prices[i] - prices[i+1] == 1){
                cnt++;
                count += cnt;
            }
            else cnt = 0;
        }

        return count;
    }
};