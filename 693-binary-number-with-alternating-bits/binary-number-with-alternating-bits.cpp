class Solution {
public:
    bool hasAlternatingBits(int n) {
        string str = "";
        if(n%2 == 0) str += '0';
        else str += '1';
        n = n >> 1;

        while(n > 0){
            char ch;
            if(n%2 == 0) ch = '0';
            else ch = '1';

            if(ch == str[str.length()-1]) return false;

            str += ch;

            n = n >> 1;
        } 

        return true;
    }
};