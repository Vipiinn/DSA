class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = n*n;
        int total = m * (m+1) / 2;

        unordered_set<int>st;

        int dup = -1;
        int sum = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                sum += grid[i][j];
                if(st.size() == 0){
                    st.insert(grid[i][j]);
                }
                else{
                    if(st.find(grid[i][j]) != st.end()){
                        dup = grid[i][j];
                    }
                    else{
                        st.insert(grid[i][j]);
                    }
                }
            }
        }

        int missing = total - sum + dup;

        return {dup , missing};
        
        
    }
};