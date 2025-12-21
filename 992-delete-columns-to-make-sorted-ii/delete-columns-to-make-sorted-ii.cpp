class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size();

        int count = 0;
        vector<bool> sorted(n - 1, false); 

        for (int col = 0; col < m; col++) {
            bool flag = false;

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] > strs[row + 1][col]) {
                    count++;
                    flag = true;
                    break;
                }
            }

            if (flag) continue; 

            for (int row = 0; row < n - 1; row++) {
                if (!sorted[row] && strs[row][col] < strs[row + 1][col]) {
                    sorted[row] = true;
                }
            }
        }

        return count;
    }
};
