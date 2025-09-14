class Solution {
private:
    void bfs(int node, vector<vector<int>> &adjLs, vector<int> &vis){
        vis[node] = 1;
        queue<int> q;
        q.push(node);

        while(!q.empty()) {
            int i = q.front();
            q.pop();

            for(auto adjNode : adjLs[i]) {
                if(vis[adjNode] == false) {
                    vis[adjNode] = 1;
                    q.push(adjNode);
                }
            }
        }
    }

public:
    int findCircleNum(vector<vector<int>> isConnected) {
        int V = isConnected.size();
        vector<vector<int>> adjLs(V);   
        vector<int> vis(V, 0);         

        for(int i = 0; i < V; i++) {
            for(int j = 0; j < V; j++) {
                if(isConnected[i][j] == 1 && i != j) {
                    adjLs[i].push_back(j);
                    adjLs[j].push_back(i);
                }
            }
        }

        int cnt = 0;
        for(int i = 0; i < V; i++) {
            if (vis[i] == false) {
                cnt++;
                bfs(i, adjLs, vis);
            }
        }
        return cnt;
    }
};
