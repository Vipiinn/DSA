class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& arr) {
        vector<vector<string>>ans;

        unordered_map<string,vector<string>>mp;

        for(auto str : arr){
            string lexo = str;
            sort(lexo.begin() , lexo.end());
            vector<string>v;
            v.push_back(str);

            if(mp.find(lexo) == mp.end()){
                mp[lexo] = v;
            }
            else{
                mp[lexo].push_back(str);
            }
        }

        for(auto x : mp){
            vector<string>v = x.second;
            ans.push_back(v);
        }

        return ans;
    }
};