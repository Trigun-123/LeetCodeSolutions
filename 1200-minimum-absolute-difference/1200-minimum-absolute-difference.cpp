class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
        int n = arr.size();
        vector<vector<int>> result;
        int minn = INT_MAX; 
        sort(arr.begin(),arr.end());

        for(int i = 0; i < n-1; i++) {
            minn = min(minn, arr[i+1]-arr[i]);
        }

        for(int i = 0; i < n-1; i++) {
            if(arr[i+1]-arr[i] == minn) {
                result.push_back({arr[i], arr[i+1]});
            }
        }

        return result;
    }
};