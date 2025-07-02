class Solution {
private:
    void func(vector<int>& vec, int i, int sum, vector<int>& v2, vector<vector<int>>& result) {
        if(sum == 0) {
            result.push_back(v2);
            return;
        }
        if (sum < 0 || i < 0)
            return;
        func(vec, i - 1, sum, v2, result);
        v2.push_back(vec[i]);
        func(vec, i, sum - vec[i], v2, result);
        v2.pop_back();
    }

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        vector<int> vec;
        func(candidates, candidates.size() - 1, target, vec, result);
        return result;
    }
};