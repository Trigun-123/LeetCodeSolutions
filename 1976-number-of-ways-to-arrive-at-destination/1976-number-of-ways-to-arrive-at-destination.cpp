#define P pair<long long,int>

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9 + 7; 
        vector<pair<int,int>> adj[n];
        
        for(auto it : roads) {
            adj[it[0]].push_back({it[1] , it[2]});
            adj[it[1]].push_back({it[0] , it[2]});
        }

        vector<long long> minTime(n, LLONG_MAX);
        vector<int> ways(n, 0);
        priority_queue <P, vector<P>, greater<P>> pq;
        minTime[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});
        
        while(!pq.empty()) {
            auto p = pq.top(); 
            pq.pop();
            long long time = p.first; 
            int node = p.second; 
            
            for(auto it : adj[node]) {
                int adjNode = it.first; 
                int travelTime = it.second;
                if(minTime[adjNode] > time + travelTime) {
                    minTime[adjNode] = time + travelTime;
                    ways[adjNode] = ways[node];
                    pq.push({minTime[adjNode], adjNode});
                } 
                else if(minTime[adjNode] == time + travelTime) {
                    ways[adjNode] = (ways[adjNode] + ways[node]) % mod;
                }
            }
        }
        return ways[n-1] % mod;
    }
};