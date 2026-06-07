class Solution {
public:

    int checkOdd(string num){
        for(int i=num.length()-1;i>=0;i--){
            int n = num[i] - '0';
            if(n % 2 != 0) return i;
        }

        return -1;
    }

    string largestOddNumber(string num) {

        int idx = checkOdd(num);
        
        if(idx >= 0){
            return num.substr(0,idx+1);
        }else{
            return "";
        }
    }
};