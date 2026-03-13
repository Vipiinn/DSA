class Solution {
public:

    bool isVowel(char ch){
        return (ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||
                ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U');
    }

    string reverseVowels(string s) {
        int st = 0;
        int end = s.length() - 1;

        while(st < end){
            while(st < end && !isVowel(s[st])) st++;
            while(st < end && !isVowel(s[end])) end--;

            swap(s[st] , s[end]);
            st++;
            end--;
        }

        return  s;
    }
};