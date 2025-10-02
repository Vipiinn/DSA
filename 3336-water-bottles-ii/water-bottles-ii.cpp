class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int ans = numBottles;
        int empty = numBottles;
        int full = 0;
        while(empty >= numExchange){
            empty -= numExchange;
            full++;
            numExchange++;
        }
        ans += full;
        empty += full;
        full = 0;
        if(empty >= numExchange){
            ans++;
        }
        return ans;
        // while(empty >= numExchange){
        //     empty -= numExchange;
        //     full++;
        //     numExchange++;
        // }
        // ans += full;
        // return ans;
    }
};