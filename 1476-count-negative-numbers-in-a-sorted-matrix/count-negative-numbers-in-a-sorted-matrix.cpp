class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        
        int n = grid.size();
        int m = grid[0].size();

        int st = 0;
        int end = m-1;

        int count = 0;

        while(st < n && end >= 0){
            
            int element = grid[st][end];

            if(element >= 0){
                st++;
            }
            else{
                count += (n-st);
                end--;
            }
        }

        return count;
    }
};