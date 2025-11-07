class Solution {
public:

    bool closeStrings(string str1, string str2) {
        if(str1.length() != str2.length()) return false;

        unordered_map<char,int>mp1;
        unordered_map<char,int>mp2;

        for(int i=0;i<str1.length();i++){
            mp1[str1[i]]++;
            mp2[str2[i]]++;
        }

        for(auto x : mp1){
            char ch = x.first;
            if(mp2.find(ch) == mp2.end()) return false;
        }

        unordered_map<int,int>m1;
        unordered_map<int,int>m2;

        for(auto x : mp1){
            int freq = x.second;
            m1[freq]++;
        }

        for(auto x : mp2){
            int freq = x.second;
            m2[freq]++;
        }

        for(auto x : m1){
            int key = x.first;
            if(m2.find(key) == m2.end()) return false;
            if(m2[key] != m1[key]) return false;
        }

        return true;

    }
};