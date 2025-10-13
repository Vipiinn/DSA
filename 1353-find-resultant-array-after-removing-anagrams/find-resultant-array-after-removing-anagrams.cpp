class Solution {
public:

    bool isAnagram(string s, string t) {

        if(s.length() != t.length()) return false;
        sort(s.begin() , s.end());
        sort(t.begin() , t.end());

        return s == t;
    }

    vector<string> removeAnagrams(vector<string>& words) {
       
        int i = 1;
        while(i < words.size()){
            if(isAnagram(words[i] , words[i-1])){
                words.erase(words.begin() + i);
            }
            else{
                i++;
            }
        }
        return words;
    }
};