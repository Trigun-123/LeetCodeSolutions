class Solution {
private:
    void func(int open, int close, int n, string s, vector<string> &result) {
        if(open == close && (open + close) == 2 * n) {
            result.push_back(s); 
            return; 
        }
        if(open < n)
            func(open + 1, close, n, s + '(', result); 
        if(close < open)
            func(open, close + 1, n, s + ')', result); 
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        func(0, 0, n, "", result);
        return result;
    }
};