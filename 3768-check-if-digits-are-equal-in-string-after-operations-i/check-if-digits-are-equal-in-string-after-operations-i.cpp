class Solution {
public:
    bool hasSameDigits(string s) {
        string ans = "";
        while(s.size() != 2){
            for(int i=0;i<s.size()-1;i++){
                int val1 = s[i] - '0';
                int val2 = s[i+1] - '0';
                ans += (val1 + val2) % 10;
            }
            s = ans;
            ans = "";
        }
        if(s[0] != s[1]) return false;
        else return true;
    }
};