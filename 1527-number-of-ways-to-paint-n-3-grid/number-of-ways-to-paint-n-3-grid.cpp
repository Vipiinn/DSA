class Solution {
public:
    int numOfWays(int n) {
        const int MOD = 1e9 + 7;
        
       
        long long typeA = 6; 
        long long typeB = 6;
        
        for (int i = 2; i <= n; i++) {
            long long newA = (2 * typeA + 2 * typeB) % MOD;
            long long newB = (2 * typeA + 3 * typeB) % MOD;
            typeA = newA;
            typeB = newB;
        }
        
        return (typeA + typeB) % MOD;
    }
};
