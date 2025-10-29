class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(auto &it: times){
            adj[it[0]].push_back({it[1], it[2]});
        }

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k});
        vector<int> dist(n+1, 1e9);
        dist[k] = 0;

        while(pq.empty() == false){
            auto[currentDist, node] = pq.top();
            pq.pop();
            if(currentDist > dist[node])
                continue;
            for(auto &[adjNode, weight]: adj[node]){
                if(currentDist + weight < dist[adjNode]){
                    dist[adjNode] = currentDist + weight;
                    pq.push({dist[adjNode], adjNode});
                }
            }
        }

        int maxDist = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9)
                return -1;
            maxDist = max(maxDist, dist[i]);
        }
        return maxDist;
    }
};