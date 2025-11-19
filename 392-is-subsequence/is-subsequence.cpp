class Solution {
public:
    bool isSubsequence(string s, string t) {
        if(s.size() == 0) return true;
        int i = 0;
        int j = 0;

        while(j < t.size()){
            if(s[i] == t[j]){
                i++;
                j++;
                if(i == s.size()) return true;
            }
            else{
                j++;
                if(j == t.size()-1 && s[i] != t[j]) return false;
            }
        }

        if(i < s.size()) return false;
        else return true;

    }
};