class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, vector<int>> mpp;

        for(int i = 0; i < n; i++) {
            mpp[nums[i]].push_back(i);
        }

        vector<long long> result(n, 0);

        for(auto it : mpp) {
            vector<int> index = it.second;
            int m = index.size();
            vector<long long> prefix(m + 1, 0);

            for(int i = 0; i < m; i++) {
                prefix[i + 1] = prefix[i] + index[i];
            }

            for(int i = 0; i < m; i++) {
                long long left = (long long)i * index[i] - prefix[i];
                long long right = (prefix[m] - prefix[i]) - (long long)(m - i) * index[i];
                result[index[i]] = left + right;
            }
        }

        return result;
    }
};