class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int ans = numBottles;
        int total = numBottles;
        while(total >= numExchange){
            int exchange = total / numExchange;
            ans += exchange;
            int empty = total % numExchange;
            total = exchange + empty;
        }
        return ans;
    }
};