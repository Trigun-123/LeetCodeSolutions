class Solution {
private:
    void solve(int src, int dest, vector<vector<int>>& graph, vector<bool>& visited, vector<int>& path, vector<vector<int>>& result) {
        if(src == dest) {
            path.push_back(dest);
            result.push_back(path);
            path.pop_back();
            return;
        }

        visited[src] = true;
        path.push_back(src);

        for(auto it : graph[src]) {
            if(!visited[it]) {
                solve(it, dest, graph, visited, path, result);
            }
        }

        path.pop_back();
        visited[src] = false;
    }

public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>> result;
        vector<int> path;
        vector<bool> visited(n, false);
        solve(0, n - 1, graph, visited, path, result);

        return result;
    }
};