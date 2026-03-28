class Solution {
public:
    string reverseWords(string s) {
        stringstream ss(s);
        string temp, result;

        while(ss >> temp) {
            reverse(temp.begin(),temp.end());
            result += (temp+" ");
        }

        int n = result.size();
        
        return result.substr(0, n-1);
    }
};