class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        
        int n = apple.size();
        int totalApple = 0;
        for(int i=0;i<n;i++){
            totalApple += apple[i];
        }

        sort(capacity.begin(),capacity.end());

        int m = capacity.size();
        int count = 0;
        int boxes = 0;

        for(int i=m-1;i>=0;i--){
            boxes += capacity[i];
            count++;
            if(boxes >= totalApple) return count;
        }

        return count;
    }
};