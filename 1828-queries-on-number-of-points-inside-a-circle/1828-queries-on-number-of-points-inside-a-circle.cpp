class Solution {
public:
    vector<int> countPoints(vector<vector<int>>& points, vector<vector<int>>& queries) {
        int n = points.size(), m = queries.size();
        int count = 0;
        vector<int> result;

        for(int i = 0; i < m; i++) {
            for(int j = 0 ; j < n; j++) {
                int x = pow((queries[i][0] - points[j][0]), 2);
                int y = pow((queries[i][1] - points[j][1]), 2);
                float distance = sqrt(x+y);

                if(dist <= queries[i][2]) {
                    count++;
                }
            }
            result.pushk(count);
            count = 0;
        }

        return result;
    }
};