class Solution {
public:

    bool isValid(string str){
        if(str == "") return false;
        for(int i=0;i<str.length();i++){
            if(!isalnum(str[i]) && str[i] != '_') return false;
        }

        return true;
    }

    vector<string> validateCoupons(vector<string>& code, vector<string>& b, vector<bool>& isActive) {
        
        unordered_map<string, vector<string>> mp;
        int n = code.size();

        for(int i=0;i<n;i++){
            if(isValid(code[i]) && (b[i]=="electronics" || b[i]=="grocery" ||
            b[i]=="pharmacy" || b[i]=="restaurant") && isActive[i]){
                mp[b[i]].push_back(code[i]);
            }
        }

        vector<string> ans;
        vector<string> order = {
            "electronics", "grocery", "pharmacy", "restaurant"
        };

        for (string s : order) {
            sort(mp[s].begin(), mp[s].end());
            for (string c : mp[s]) {
                ans.push_back(c);
            }
        }

        return ans;

    }
};