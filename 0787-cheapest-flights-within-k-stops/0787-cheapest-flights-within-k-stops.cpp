#define P pair<int, pair<int, int>>

class Solution{
public:
    int findCheapestPrice(int n, vector<vector<int>> &flights, int src, int dst, int k) {
        vector<pair<int,int>> adj[n];
        
        for(auto it : flights) {
            adj[it[0]].push_back({it[1], it[2]});
        }
        
        vector<int> minDist(n, 1e9);
        minDist[src] = 0;
        queue <P> q;
        q.push({0, {src, 0}});
        
        while(!q.empty()) {
            auto p = q.front(); q.pop();
            int stops = p.first;
            int node = p.second.first; 
            int dist = p.second.second; 

            if(stops > k) 
                continue;
            
            for(auto it : adj[node]) {
                int adjNode = it.first; 
                int edgeWt = it.second; 
                if(dist + edgeWt < minDist[adjNode] && stops <= k) {
                    minDist[adjNode] = dist + edgeWt;
                    q.push({stops+1, {adjNode, dist + edgeWt}});
                }
            }
        }
        if(minDist[dst] == 1e9) 
            return -1;
    
        return minDist[dst];
    }
};
