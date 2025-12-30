class Solution {
public:
    bool check(vector<vector<int>>& g, int r, int c) {
        bool used[10] = {false};

        for (int i = r; i < r + 3; i++) {
            for (int j = c; j < c + 3; j++) {
                int x = g[i][j];
                if (x < 1 || x > 9 || used[x])
                    return false;
                used[x] = true;
            }
        }

        int s = g[r][c] + g[r][c+1] + g[r][c+2];

        for (int i = 0; i < 3; i++)
            if (g[r+i][c] + g[r+i][c+1] + g[r+i][c+2] != s)
                return false;

        for (int j = 0; j < 3; j++)
            if (g[r][c+j] + g[r+1][c+j] + g[r+2][c+j] != s)
                return false;

        if (g[r][c] + g[r+1][c+1] + g[r+2][c+2] != s)
            return false;
        if (g[r][c+2] + g[r+1][c+1] + g[r+2][c] != s)
            return false;

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans = 0;
        for (int i = 0; i + 2 < grid.size(); i++) {
            for (int j = 0; j + 2 < grid[0].size(); j++) {
                if (check(grid, i, j))
                    ans++;
            }
        }
        return ans;
    }
};
