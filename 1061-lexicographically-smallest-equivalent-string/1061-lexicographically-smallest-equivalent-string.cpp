class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char ch[26];

        for(int i = 0; i < 26; i++) {
            ch 'a' + i;
        }    

        for(int i = 0; i < s1.size(); i++) {
            char toReplace = max(ch[s1[i]-'a'], ch[s2[i]-'a']);
            char replach[s1[i]-'a'], ch[s2[i]-'a']);

            for(int i = 0; i < 26; i++) {
                if(ch[i] == toReplace) {
                    ch[i] = replaceWith;
                }
            }        
        }
        
        for(int i = 0; i < baseStr.size(); i++) {
            ba= ch[baseStr[i]-'a'];
        }    

        return baseStr;
    }
};