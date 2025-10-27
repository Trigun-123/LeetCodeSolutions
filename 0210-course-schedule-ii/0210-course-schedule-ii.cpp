class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        // Build adjacency list: v → u means u depends on v
        for (auto it : prerequisites) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }
        
        // Step 1: Calculate indegree of each node
        vector<int> inDegree(numCourses, 0);
        for (int i = 0; i < numCourses; i++) {
            for (auto it : adj[i]) {
                inDegree[it]++;
            }
        }

        // Step 2: Push all nodes with indegree 0 into queue
        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (inDegree[i] == 0)
                q.push(i);
        }

        // Step 3: Perform Kahn’s Algorithm (BFS for topological sort)
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

        // Step 4: If topological sort includes all nodes, return it
        if (topo.size() < numCourses)
            return {};
        
        return topo;
    }
};
