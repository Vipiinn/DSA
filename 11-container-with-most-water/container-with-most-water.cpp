class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int st = 0;
        int end = n-1;
        int area = 1;
        int ans = INT_MIN;
        while(st < end){
            area = (end-st) * min(height[st] , height[end]);
            if(height[st] < height[end]){
                st++;
            }
            else{
                end--;
            }
            ans = max(ans,area);
        }
        return ans;
    }
};