class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int totalTime = 0, currentMaxTime = 0;

        for(int i = 0; i < n; i++) {
            if(i > 0 && colors[i] != colors[i - 1])
                currentMaxTime = 0;

            totalTime += min(currentMaxTime, neededTime[i]);
            currentMaxTime = max(currentMaxTime, neededTime[i]);
        }
        return totalTime;
    }
};