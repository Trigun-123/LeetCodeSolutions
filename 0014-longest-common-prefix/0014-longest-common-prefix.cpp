class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();
        sort(strs.begin(), strs.end());
        string first = strs[0];
        string last = strs[n-1];
        string result = "";

        for(int i = 0; i < min(first.length(), last.length()); i++) {
            if(first[i] != last[i])
                break;
            result += first[i]; 
        }
        return result;
    }
};