class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>m;

        for(int i=0;i<n;i++){
            m[nums[i]]++;
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;


        for(auto ele : m){
            pq.push({ele.second , ele.first});
            if(pq.size() > k) pq.pop();
        }

        vector<int>ans;

        while(pq.size() > 0){
            pair<int,int>p = pq.top();
            ans.push_back(p.second);
            pq.pop();
        }

        return ans;

    }
};