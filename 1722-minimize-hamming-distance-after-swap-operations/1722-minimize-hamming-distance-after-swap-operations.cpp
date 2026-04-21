class Solution {
private: 
    void dfs(int u, vector<vector<int>>& adj, vector<int>& visited,vector<int>& source, vector<int>& target, map<int,int>& mpp) {
        mpp[source[u]]++;
        mpp[target[u]]--;
        visited[u] = 1;

        for(auto it : adj[u]) {
            if(!visited[it]) {
                dfs(it, adj, visited, source, target, mpp);
            }
        }
    }

public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target,
    vector<vector<int>>& allowedSwaps) {
        int n = source.size();
        vector<vector<int>> adj(n);

        for(auto it : allowedSwaps) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }

        vector<int> visited(n, 0);
        int result = 0;

        for(int i = 0; i < n; i++) {
            if(!visited[i]) {
                map<int,int> mpp;
                dfs(i, adj, visited, source, target, mpp);

                for(auto [k, w] : mpp) {
                    result += abs(w);
                }
            }
        }

        return result / 2;
    }
};