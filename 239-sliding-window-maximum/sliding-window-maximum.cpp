class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>ngi(n);
        stack<int>st;

        ngi[n-1] = n;
        st.push(n-1);

        for(int i=n-2;i>=0;i--){
            //pop
            while(st.size() > 0 && nums[st.top()] <= nums[i]){
                st.pop();
            }
            //store
            if(st.size() == 0) ngi[i] = n;
            else ngi[i] = st.top();
            //push
            st.push(i);
        }

        vector<int>ans;
        int j = 0;

        for(int i=0;i<n-k+1;i++){
            if(j < i)  j = i;
            int mx = nums[j];
            while(j < i+k){
                mx = nums[j];
                if(ngi[j] >= i+k) break;
                j = ngi[j];
            }
            ans.push_back(mx);
        }
        return ans;
    }
};