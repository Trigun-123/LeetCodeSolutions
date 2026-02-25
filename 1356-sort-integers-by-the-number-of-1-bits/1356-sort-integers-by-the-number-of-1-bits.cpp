class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        int n = arr.size();
        vector<pair<int,int>> result;

        for(auto it : arr) {
            int number = it;
            int count = 0;

            while(number) {
                if(number & 1) {
                    count++;
                }
                number >>= 1;
            }
            result.push_back({count, it});
        }

        sort(result.begin(), result.end());

        for(int i = 0; i < n; i++) {
            arr[i] = result[i].second;
        }

        return arr;
    }
};