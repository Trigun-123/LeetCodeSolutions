class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> adjMat(n, vector<int>(n, 1e9));
        for(auto it : edges) {
            adjMat[it[0]][it[1]] = it[2];
            adjMat[it[1]][it[0]] = it[2];
        }
        for(int k = 0; k < n; k++) {
            for(int i = 0; i < n; i++) {
                for(int j = 0; j < n; j++) {
                    adjMat[i][j] = min(adjMat[i][j], adjMat[i][k] + adjMat[k][j]);
                }
            }
        }
        int minCount = 1e9;
        int ans;
        for(int i = 0; i < n; i++) {
            int count = 0;
            for(int j = 0; j < n; j++) {
                if(i != j && adjMat[i][j] <= distanceThreshold)
                    count++;
            }
            if(count < minCount) {
                minCount = count;
                ans = i;
            }
            else if(count == minCount)
                ans = i;
        }
        return ans;
    }
};
