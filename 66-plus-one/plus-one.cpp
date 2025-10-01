class Solution {
public:
    vector<int> plusOne(vector<int>& a) {
        vector<int>b;
        b.push_back(1);
        vector<int>ans;
        int n = a.size();
        int m = b.size();
        int sum = 0;
        int carry = 0;
        int i = n - 1;
        int j = m - 1;
        while(i >= 0 && j >= 0){
            sum = a[i] + b[j] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
            j--;
        }

        while(i >= 0){
            sum = a[i] + carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
            i--;
        }

        while(carry != 0){
            sum = carry;
            carry = sum / 10;
            sum = sum % 10;
            ans.push_back(sum);
        }
        reverse(ans.begin() , ans.end());
        return ans;
    }
};