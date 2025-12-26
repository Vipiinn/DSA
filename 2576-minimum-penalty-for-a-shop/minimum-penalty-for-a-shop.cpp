class Solution {
public:
    int bestClosingTime(string customers) {
        
        int n = customers.size();

        vector<int>pre(n+1,0);
        vector<int>suff(n+1,0);

        for(int i=1;i<=n;i++){
            if(customers[i-1] == 'N'){
                pre[i] = pre[i-1] + 1;
            }
            else pre[i] = pre[i-1];
        }

        for(int i=n-1;i>=0;i--){
            if(customers[i] == 'Y'){
                suff[i] = suff[i+1] + 1;
            }
            else suff[i] = suff[i+1];
        }

        int idx = 0;
        int mini = INT_MAX;
        for(int i=0;i<=n;i++){
            int penalty = pre[i]+suff[i];
            if(penalty < mini){
                mini = penalty;
                idx = i;
            }
        }

        return idx;
    }
};