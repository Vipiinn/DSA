class Solution {
public:
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        
        string word(n + m - 1, '?');
        vector<bool> fixed(n + m - 1, false);
        
        // Step 1: Apply 'T'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'T'){
                for(int j = 0; j < m; j++){
                    if(word[i+j] == '?' || word[i+j] == str2[j]){
                        word[i+j] = str2[j];
                        fixed[i+j] = true;  
                    } else {
                        return "";
                    }
                }
            }
        }
        
        // Step 2: Fill remaining with 'a'
        for(char &c : word){
            if(c == '?') c = 'a';
        }
        
        // Step 3: Handle 'F'
        for(int i = 0; i < n; i++){
            if(str1[i] == 'F'){
                if(word.substr(i, m) == str2){
                    
                    bool changed = false;
                    
                    for(int j = m-1; j >= 0; j--){
                        int pos = i + j;

                        if(fixed[pos]) continue;  
                        
                        for(char c = 'a'; c <= 'z'; c++){
                            if(c != word[pos]){
                                word[pos] = c;
                                changed = true;
                                break;
                            }
                        }
                        
                        if(changed) break;
                    }
                    
                    if(!changed) return "";
                }
            }
        }
        
        return word;
    }
};