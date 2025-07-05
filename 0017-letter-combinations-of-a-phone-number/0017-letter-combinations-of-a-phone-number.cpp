class Solution {
private:
    void func(int ind, string digits, string s, vector<string> &ans, string combos[]) {
        if(ind == digits.size()) {
            ans.push_back(s);
            return;
        }
        int digit = digits[ind] - '0';
        for(int i = 0; i < combos[digit].size(); i++)
            func(ind + 1, digits, s + combos[digit][i], ans, combos);
    }

public:
    vector<string> letterCombinations(string digits) {
        if(digits.empty())
            return {}; 
        string combos[] = {" ", " ", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        vector<string> ans; 
        string s; 
        func(0, digits, s, ans, combos);
        return ans; 
    }
};