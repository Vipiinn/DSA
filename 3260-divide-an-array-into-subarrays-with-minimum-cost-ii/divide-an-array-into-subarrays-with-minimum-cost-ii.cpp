class Solution {
public:
    long long minimumCost(vector<int>& nums, int k, int dist) {
        int n = nums.size();

        multiset<int> small, large;
        long long sumSmall = 0;

        auto rebalance = [&]() {
            while ((int)small.size() > k - 1) {
                auto it = prev(small.end());
                sumSmall -= *it;
                large.insert(*it);
                small.erase(it);
            }
            while ((int)small.size() < k - 1 && !large.empty()) {
                auto it = large.begin();
                sumSmall += *it;
                small.insert(*it);
                large.erase(it);
            }
        };

        auto add = [&](int x) {
            if (!small.empty() && x > *prev(small.end())) {
                large.insert(x);
            } else {
                small.insert(x);
                sumSmall += x;
            }
            rebalance();
        };

        auto remove = [&](int x) {
            if (small.find(x) != small.end()) {
                sumSmall -= x;
                small.erase(small.find(x));
            } else {
                large.erase(large.find(x));
            }
            rebalance();
        };

        int Rmax = min(n - 1, dist + 1);
        for (int i = 1; i <= Rmax; i++) {
            add(nums[i]);
        }

        long long ans = sumSmall;  

        int L = 1;
        for (int R = Rmax + 1; R < n; R++) {
            add(nums[R]);
            remove(nums[L]);
            L++;
            ans = min(ans, sumSmall);
        }

        return nums[0] + ans; 
    }
};
