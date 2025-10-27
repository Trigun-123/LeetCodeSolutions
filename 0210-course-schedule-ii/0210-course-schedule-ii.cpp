class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
    
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
       
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        vector<int> topo;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            topo.push_back(node);

            for (auto it : adj[node]) {
                inDegree[it]--;
                if (inDegree[it] == 0)
                    q.push(it);
            }
        }

        if (topo.size() < numCourses)
            return {};
        
        return topo;
    }
};
