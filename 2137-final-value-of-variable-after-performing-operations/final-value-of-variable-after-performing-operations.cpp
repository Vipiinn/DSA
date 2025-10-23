class Solution {
public:
    int finalValueAfterOperations(vector<string>& op) {
        int n = op.size();
        int val = 0;
        for(int i=0;i<n;i++){
            if(op[i] == "++X") ++val;
            else if(op[i] == "X++") val++;
            else if(op[i] == "--X") --val;
            else val--;
        }

        return val;
    }
};