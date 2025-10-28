#define P pair <int, pair<int,int>>
class Solution {
private:
    vector<int> delRow = {-1, 0, 1, 0};
    vector<int> delCol = {0, -1, 0, 1};
    
    bool isValid(int &row, int &col, int &n, int &m) {
        if(row < 0 || row >= n) 
            return false;
        if(col < 0 || col >= m) 
            return false;
        return true;
    }

public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> maxDiff(n, vector<int>(m, 1e9));
        priority_queue <P, vector<P>, greater<P>> pq;
        maxDiff[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()) {
            auto p = pq.top();
            int diff = p.first;
            int row = p.second.first; 
            int col = p.second.second; 
            pq.pop();
            
            if(row == n-1 && col == m-1) 
                return diff;
            
            for(int i=0; i<4; i++) {
                int newRow = row + delRow[i];
                int newCol = col + delCol[i];
                if(isValid(newRow, newCol, n, m)) {
                    int currDiff = abs(heights[newRow][newCol] - heights[row][col]);
                    if(max(currDiff, diff) < maxDiff[newRow][newCol]) {
                        maxDiff[newRow][newCol] = max(currDiff, diff);
                        pq.push({max(currDiff, diff), {newRow, newCol}});
                    }
                }
            }
        }
        return -1;
    }
};
