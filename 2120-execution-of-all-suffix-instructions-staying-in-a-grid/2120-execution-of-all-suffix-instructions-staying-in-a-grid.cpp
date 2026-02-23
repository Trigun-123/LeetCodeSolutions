class Solution {
public:
    vector<int> executeInstructions(int n, vector<int>& startPos, string s) {
        unordered_map<char, pair<int,int>> directions = {
            {'L', {0, -1}},
            {'R', {0, 1}},
            {'U', {-1, 0}},
            {'D', {1, 0}}
        };

        int pathLength = s.length();
        int upLimit = startPos[0] + 1, downLimit = n - startPos[0];
        int leftLimit = startPos[1] + 1, rightLimit = n - startPos[1];
        int currentRow = 3, currentCol = 2;
        unordered_map<int,int> rowIndexMap, colIndexMap;
        rowIndexMap[currentRow] = pathLength;
        colIndexMap[currentCol] = pathLength;
        vector<int> result;

        for(int i = pathLength - 1; i >= 0; i--) {
            currentRow -= directions[s[i]].first;
            currentCol -= directions[s[i]].second;
            int validPathLength = pathLength - i;

            if(rowIndexMap.count(currentRow - upLimit)) {
                validPathLength = min(validPathLength, rowIndexMap[currentRow - upLimit] - i - 1);
            }

            if(rowIndexMap.count(currentRow + downLimit)) {
                validPathLength = min(validPathLength, rowIndexMap[currentRow + downLimit] - i - 1);
            }

            if(colIndexMap.count(currentCol - leftLimit)) {
                validPathLength = min(validPathLength, colIndexMap[currentCol - leftLimit] - i - 1);
            }

            if(colIndexMap.count(currentCol + rightLimit)) {
                validPathLength = min(validPathLength, colIndexMap[currentCol + rightLimit] - i - 1);
            }

            result.push_back(validPathLength);
            rowIndexMap[currentRow] = i;
            colIndexMap[currentCol] = i;
        }
        reverse(result.begin(), result.end());
        
        return result;
    }
};