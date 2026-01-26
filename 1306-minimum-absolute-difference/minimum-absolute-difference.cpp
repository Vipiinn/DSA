class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        
        vector<vector<int>>ans;
        sort(arr.begin() , arr.end());

        int diff = abs(arr[0]-arr[1]);
        ans.push_back({arr[0] , arr[1]});

        for(int i=1;i<arr.size()-1;i++){
            if(abs(arr[i] - arr[i+1]) == diff){
                ans.push_back({arr[i] , arr[i+1]});
            }
            else if(abs(arr[i] - arr[i+1]) < diff){
                diff = abs(arr[i] - arr[i+1]);
                ans.clear();
                ans.push_back({arr[i] , arr[i+1]});
            }
        }

        return ans;
        
    }
};