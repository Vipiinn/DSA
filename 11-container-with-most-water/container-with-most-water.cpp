class Solution {
public:
    int maxArea(vector<int>& ht) {
        
        int maxiArea = INT_MIN;
        int st = 0;
        int end = ht.size() - 1;
        int area = 1;

        while(st < end){

            area = (end-st) * min(ht[st] , ht[end]);
            maxiArea = max(maxiArea , area);

            if(ht[st] < ht[end]){
                st++;
            }
            else end--;
        }

        return maxiArea;

    }
};