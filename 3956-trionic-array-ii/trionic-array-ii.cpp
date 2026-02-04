class Solution {
public:
    long long maxSumTrionic(vector<int>& nums) {
        int n = nums.size();
        const long long NEG = LLONG_MIN / 4;

        vector<long long> inc(n, NEG);        // increasing
        vector<long long> incDec(n, NEG);     // increasing -> decreasing
        vector<long long> incDecInc(n, NEG);  // increasing -> decreasing -> increasing

        // 1) Increasing (len >= 2)
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                inc[i] = nums[i - 1] + nums[i];
                if (inc[i - 1] != NEG)
                    inc[i] = max(inc[i], inc[i - 1] + nums[i]);
            }
        }

        // 2) Increasing -> Decreasing (len >= 2 for both)
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] > nums[i]) {
                if (inc[i - 1] != NEG)
                    incDec[i] = inc[i - 1] + nums[i];
                if (incDec[i - 1] != NEG)
                    incDec[i] = max(incDec[i], incDec[i - 1] + nums[i]);
            }
        }

        // 3) Increasing -> Decreasing -> Increasing (final phase extendable)
        long long ans = NEG;
        for (int i = 1; i < n; i++) {
            if (nums[i - 1] < nums[i]) {
                if (incDec[i - 1] != NEG)
                    incDecInc[i] = incDec[i - 1] + nums[i];
                if (incDecInc[i - 1] != NEG)
                    incDecInc[i] = max(incDecInc[i], incDecInc[i - 1] + nums[i]);
            }
            ans = max(ans, incDecInc[i]);
        }

        return ans;
    }
};
