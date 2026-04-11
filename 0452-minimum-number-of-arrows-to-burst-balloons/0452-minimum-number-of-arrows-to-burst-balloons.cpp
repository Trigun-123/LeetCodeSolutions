class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        sort(points.begin(), points.end(), [](const vector<int>& x, const vector<int>& y) {
            return x[1] < y[1];
        });
        int count = 1, last = points[0][1];

        for(int i = 1; i < n; i++) {
            if(points[i][0] > last) {
                count++;
                last = points[i][1];
            }
        }

        return count;
    }
};