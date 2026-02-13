class Solution {
public:
    vector<string> stringSequence(string target) {
        int n = target.size();
        string s;
        vector<string> result;

        for(int i = 0; i < n; i++) {
            s += 'a';

            for(char ch = 'a'; ch <= 'z'; ch++) {
                s[i] = ch;
                result.push_back(s);
                if(ch == target[i]) {
                    break;
                }    
            }
        }
        
        return result;    
    }
};