class Solution {
public:

    string reverse(string str){
        int i = 0;
        int j = str.length() - 1;
        bool flag = false;
        while(i < j){
            if(str[i] != str[j]){
                swap(str[i] , str[j]);
                flag = true;
            }
            i++;
            j--;
        }
        if(flag == false) return "NO";
        else return str;
    }

    int maximumNumberOfStringPairs(vector<string>& words) {

        int n = words.size();
        
        unordered_set<string>s;

        for(int i=0;i<n;i++){
            string str = reverse(words[i]);
            if(str != "NO") words.push_back(str);
        }

        for(int i=0;i<words.size();i++){
            s.insert(words[i]);
        }

        int ans = words.size() - s.size();

        return ans / 2;


    }
};