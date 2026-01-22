#include <vector>
using namespace std;

class Solution {
public:
    bool isNonDecreasing(vector<int>& nums) {
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1])
                return false;
        }
        return true;
    }

    int minimumPairRemoval(vector<int>& nums) {
        int operations = 0;

        while (!isNonDecreasing(nums)) {
            int minSum = nums[0] + nums[1];
            int index = 0;

            for (int i = 1; i < nums.size() - 1; i++) {
                int currSum = nums[i] + nums[i + 1];
                if (currSum < minSum) {
                    minSum = currSum;
                    index = i;
                }
            }
            nums[index] = minSum;
            nums.erase(nums.begin() + index + 1);

            operations++;
        }

        return operations;
    }
};
