class Solution {
public:
    vector<int> findErrorNums(vector<int>& arr) {
        sort(arr.begin(),arr.end());
        int dup = -1;
        int n = arr.size();
        int sum = arr[n-1];
        int ans = n * (n + 1) / 2;

        for(int i=0;i<n-1;i++){
            if(arr[i] == arr[i+1]){
                dup = arr[i];
            }
            sum += arr[i];
        }

        sum = sum - dup;
        ans = ans - sum;

        return {dup , ans};
    }
};