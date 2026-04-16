class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        int size = nums.size();
        unordered_map<int, vector<int>> indexMap;

        for(int i = 0; i < size; i++) {
            indexMap[nums[i]].push_back(i);
        }

        vector<int> result;

        for(int index : queries) {
            vector<int>& positions = indexMap[nums[index]];
            if(positions.size() == 1) {
                result.push_back(-1);
                continue;
            }

            int positionIndex = lower_bound(positions.begin(), positions.end(), index) - positions.begin();
            int minDist = INT_MAX;
            int prevIndex = positions[(positionIndex - 1 + positions.size()) % positions.size()];
            int dist1 = abs(index - prevIndex);
            minDist = min(minDist, min(dist1, size - dist1));
            int nextIndex = positions[(positionIndex + 1) % positions.size()];
            int dist2 = abs(index - nextIndex);
            minDist = min(minDist, min(dist2, size - dist2));
            result.push_back(minDist);
        }

        return result;
    }
};