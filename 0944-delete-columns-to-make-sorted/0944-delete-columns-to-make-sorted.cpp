class Solution {
    bool unsorted(const vector<string>& strs, int i, int n) {
        for(int j = 1; j < n; j++) {
            if(strs[j][i] < strs[j - 1][i]) {
                return true;
            }
        }

        return false;
    }

public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size(), m = strs[0].size();
        int result = 0;

        for(int i = 0; i < m; i++) {
            result += unsorted(strs, i, n);
        }

        return result;
    }
};
