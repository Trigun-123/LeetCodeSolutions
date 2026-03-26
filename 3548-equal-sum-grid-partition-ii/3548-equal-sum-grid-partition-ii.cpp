class Solution {
private:
    bool solve(int r1, int c1, int r2, int c2, int i, int j) {
        int rows = r2 - r1 + 1, cols = c2 - c1 + 1;
        if(rows * cols == 1) {
            return false;
        }    
        if(rows == 1) {
            return (j == c1 || j == c2);
        }

        if(cols == 1) {
            return (i == r1 || i == r2);
        }

        return true;
    }

public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<long long> preRow(n, 0), preCol(m, 0);
        map<long long, vector<pair<int,int>>> mpp;

        for(int i = 0; i < n; i++) {
            long long value = 0;
            for(int j = 0; j < m; j++) {
                value += grid[i][j];
                mpp[grid[i][j]].push_back({i, j});
            }
            preRow[i] = value + (i ? preRow[i - 1] : 0);
        }

        for(int j = 0; j < m; j++) {
            long long value = 0;
            for(int i = 0; i < n; i++) {
                value += grid[i][j];
            }
            preCol[j] = value + (j ? preCol[j - 1] : 0);
        }

        long long total = preRow[n - 1];

        for(int i = 0; i < n - 1; i++) {
            long long top = preRow[i];
            long long bottom = total - top;
            if(top == bottom) {
                return true;
            }    

            long long difference = abs(top - bottom);

            if(mpp.find(difference) == mpp.end()) {
                continue;
            }    

            if(top > bottom) {
                for(auto it : mpp[difference]) {
                    int x = it.first, y = it.second;
                    if(x <= i && solve(0, 0, i, m - 1, x, y)) {
                        return true;
                    }
                }
            } 
            else {
                for(auto it : mpp[difference]) {
                    int x = it.first, y = it.second;
                    if(x > i && solve(i + 1, 0, n - 1, m - 1, x, y)) {
                        return true;
                    }
                }
            }
        }

        for(int j = 0; j < m - 1; j++) {
            long long left = preCol[j];
            long long right = total - left;
            if(left == right) {
                return true;
            }    

            long long difference = abs(left - right);

            if(mpp.find(difference) == mpp.end()) {
                continue;
            }    

            if(left > right) {
                for(auto it : mpp[difference]) {
                    int x = it.first, y = it.second;
                    if(y <= j && solve(0, 0, n - 1, j, x, y)) {
                        return true;
                    }
                }
            } 
            else {
                for(auto it : mpp[difference]) {
                    int x = it.first, y = it.second;
                    if(y > j && solve(0, j + 1, n - 1, m - 1, x, y)) {
                        return true;
                    }
                }
            }
        }

        return false;
    }
};