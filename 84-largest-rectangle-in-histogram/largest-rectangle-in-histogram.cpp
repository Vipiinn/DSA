class Solution {
public:

    void NextSmaller(vector<int>& heights , vector<int>&ans1){
        int n = heights.size();

        stack<int>st;

        for(int i=n-1;i>=0;i--){

            //pop
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            //store 
            if (!st.empty()) {
                ans1[i] = st.top();
            } else {
                ans1[i] = n; 
            }

            //push
            st.push(i);
        }

    }

    void previousSmaller(vector<int>& heights , vector<int>&ans2){
        int n = heights.size();
        stack<int>st;

        for(int i=0;i<n;i++){

            //pop
            while(st.size() > 0 && heights[st.top()] >= heights[i]){
                st.pop();
            }

            //store 
            if (!st.empty()) {
                ans2[i] = st.top();
            } else {
                ans2[i] = -1; 
            }

            //push
            st.push(i);
        }
    }

    int largestRectangleArea(vector<int>& heights) {

        int n = heights.size();
        if (n == 0) return 0;
        if (n == 1) return heights[0];

        vector<int>ans1(n);
        vector<int>ans2(n);

        NextSmaller(heights,ans1);
        previousSmaller(heights,ans2);

        int ans = INT_MIN;

        for(int i=0;i<n;i++){
            int width = ans1[i] - ans2[i] - 1;
            ans = max(ans,heights[i] * width);
        }
        return ans;
        
    }
};
