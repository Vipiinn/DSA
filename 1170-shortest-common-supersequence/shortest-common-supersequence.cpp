class Solution {
public:

    void LCS(string str1 , string str2 , vector<vector<int>>& dp){

        int n = str1.length();
        int m = str2.length();

        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i == 0 || j == 0) dp[i][j] = 0;
            }
        }

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){

                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = 1 + dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i][j-1] , dp[i-1][j]);
                }
            }
        }
    }

    string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.length();
        int m = str2.length();

        vector<vector<int>>dp(n+1 , vector<int>(m+1));
        
        LCS(str1 , str2 , dp);

        int i = n;
        int j = m;

        string ans = "";

        while(i > 0 && j > 0){

            if(str1[i-1] == str2[j-1]){
                ans.push_back(str1[i-1]);
                i--;
                j--;
            }
            else{
                if(dp[i][j-1] > dp[i-1][j]){
                    ans.push_back(str2[j-1]);
                    j--;
                }
                else {
                    ans.push_back(str1[i-1]);
                    i--;
                }
            }
        }

        while(i > 0){
            ans.push_back(str1[i-1]);
            i--;
        }

        while(j > 0){
            ans.push_back(str2[j-1]);
            j--;
        }

        reverse(ans.begin() , ans.end());

        return ans;
    }
};