class Solution {
public:

    typedef long long ll;

    long long maxProfit(vector<int>& prices, vector<int>& strategy, int k) {

        int n = prices.size();

        ll actualProfit = 0;

        vector<ll> profit(n);

        for(int i=0;i<n;i++){
            profit[i] = ll(prices[i] * strategy[i]);
            actualProfit += profit[i];
        }

        ll currWindowPro = 0; // current window ka profit 
        ll ModiWindowPro = 0; // modified window ka profit
        ll maxGain = 0;

        int i = 0;
        int j = 0;

        while(j < n){

            currWindowPro += profit[j];

            if(j - i + 1 > k/2){
                ModiWindowPro += prices[j];
            }

            if(j -i + 1 > k){ // shrink 
                currWindowPro -= profit[i];
                ModiWindowPro -= prices[i + k/2];
                i++;
            }

            if(j - i + 1 == k){
                maxGain = max(maxGain , ModiWindowPro - currWindowPro);
            }

            j++;
        }

        return actualProfit + maxGain;

        
    }
};