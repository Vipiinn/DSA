class Solution {
public:

    void fillZeroes(vector<vector<int>>& mat , int m , int n){

        int row = mat.size();
        int col = mat[0].size();

        for(int i=0;i<col;i++){
            mat[m][i] = 0;
        }

        for(int i=0;i<row;i++){
            mat[i][n] = 0;
        }
    }

    void setZeroes(vector<vector<int>>& matrix) {

        int m = matrix.size();
        int n = matrix[0].size();
        
        vector<vector<int>>mat(m , vector<int>(n));

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                mat[i][j] = matrix[i][j];
            }
        }

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == 0){
                    fillZeroes(mat , i , j);
                }
            }
        }

        matrix = mat;
    }
};