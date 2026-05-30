class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int row = matrix.size();
        int col = matrix[0].size();
        int st = 0;
        int end = col - 1;

        while(st < row && end >= 0){
            int ele = matrix[st][end];

            if(ele == target) return true;
            else if(ele < target){
                st++;
            }
            else {
                end--;
            }
        }

        return false;
    }
};