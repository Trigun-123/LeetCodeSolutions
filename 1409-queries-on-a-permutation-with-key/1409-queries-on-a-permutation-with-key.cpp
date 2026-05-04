class Solution {
public:
    vector<int> processQueries(vector<int>& queries, int m) {
        int n = queries.size();
        unordered_map<int,int> position;

        for(int i = 0; i < m; i++) {
            position[i+1] = i;
        }    

        for(int i = 0; i < n; i++) {
            int temp = queries[i];
            queries[i] = position[queries[i]];

            for(auto it : position) {
                if(it.second <= queries[i]) {
                    position[it.first]++;
                }    
                position[temp] = 0;
            }    
        }

        return queries;
    }
};