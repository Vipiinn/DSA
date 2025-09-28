class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int>ans;
        int count = 0;
        while(n > 0){
            int digit = n % 10;
            int a = digit * pow(10,count);
            if(digit != 0) ans.push_back(a);
            count++;
            n /= 10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};