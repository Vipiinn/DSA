class Solution {
public:
    int minimumDeletions(string s) {
        
        int n = s.length();
        int countB = 0;
        int deletion = 0;

        for(int i=0;i<n;i++){
            if(s[i] == 'b') countB++;
            else{
                deletion = min(deletion+1 , countB);
            }
        }

        return deletion;
    }
};