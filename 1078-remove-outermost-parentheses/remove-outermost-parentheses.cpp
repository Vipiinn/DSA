class Solution {
public:
    string removeOuterParentheses(string s) {
        int delIdx = s.length() - 1;;
        int open = 0;
        int close = 0;

        for(int i=s.length()-1;i>=0;i--){
            if(s[i] == '(') open++;
            else close++;

            if(open == close){
                s.erase(delIdx , 1);
                s.erase(i , 1); 
                open = 0;
                close = 0;
                if(i - 1 > 0) delIdx = i - 1;
            }
        }

        return s;
    }
};