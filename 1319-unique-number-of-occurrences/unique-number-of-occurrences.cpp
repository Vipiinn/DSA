class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>map;

        for(int i=0;i<arr.size();i++){
            map[arr[i]]++;
        }

        unordered_set<int>s;

        for(auto val : map){
            int freq = val.second;
            if(s.find(freq) != s.end()) return false;
            else s.insert(freq);
        }

        return true;
    }
};