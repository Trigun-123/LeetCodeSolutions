class Solution {
public:
    long long minimumTotalDistance(vector<int>& robot, vector<vector<int>>& factory) {
        int numRobots = robot.size(), numFactories = factory.size();
        sort(robot.begin(), robot.end());
        sort(factory.begin(), factory.end());
        const long long INF = 1e18;
        vector<vector<long long>> dp(numRobots + 1, vector<long long>(numFactories + 1, INF));

        for(int j = 0; j <= numFactories; j++) {
            dp[0][j] = 0;
        }    

        for(int i = 0; i <= numRobots; i++) {
            for(int j = 1; j <= numFactories; j++) {
                int factoryPosition = factory[j - 1][0];
                int capacity = factory[j - 1][1];
                dp[i][j] = dp[i][j - 1];
                long long totalDistance = 0;

                for(int k = 1; k <= capacity && i - k >= 0; k++) {
                    totalDistance += abs(robot[i - k] - factoryPosition);
                    dp[i][j] = min(dp[i][j], dp[i - k][j - 1] + totalDistance);
                }
            }
        }

        return dp[numRobots][numFactories];
    }
};