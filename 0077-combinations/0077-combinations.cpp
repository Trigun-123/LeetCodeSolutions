class Solution { 
private: 
    void solve(int n, int k, vector<vector<int>> &result, vector<int> &temp, int start) {
        if(temp.size() == k) {
            result.push_back(temp);
            return;
        }

        for(int i = start; i <= n; i++) {
            temp.push_back(i);
            solve(n, k, result, temp, i+1);
            temp.pop_back();
        }
    }     

public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> result;
        vector<int> temp;
        solve(n, k, result, temp, 1);

        return result;
    }
};