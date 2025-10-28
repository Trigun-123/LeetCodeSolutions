class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if(grid[0][0] == 1 || grid[n - 1][m - 1] == 1)
            return -1;

        vector<int> delRow = {-1, -1, -1, 0, 0, 1, 1, 1};
        vector<int> delCol = {-1, 0, 1, -1, 1, -1, 0, 1};

        queue<pair<int, pair<int, int>>> q;
        vector<vector<int>> dist(n, vector<int>(m, 1e9));

        dist[0][0] = 1; 
        q.push({1, {0, 0}});

        while(!q.empty()) {
            auto it = q.front();
            q.pop();

            int dis = it.first;
            int row = it.second.first;
            int col = it.second.second;

            if(row == n - 1 && col == m - 1)
                return dis;

            for(int i = 0; i < 8; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];

                if(newRow >= 0 && newRow < n && newCol >= 0 && newCol < m && grid[newRow][newCol] == 0 && dis + 1 < dist[newRow][newCol]) {
                    dist[newRow][newCol] = dis + 1;
                    q.push({dis + 1, {newRow, newCol}});
                }
            }
        }
        return -1;
    }
};
