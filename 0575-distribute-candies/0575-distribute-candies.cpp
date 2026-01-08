class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_map<int, int> mpp;

        for(int i = 0; i < n; i++) {
            mpp[candyType[i]]++;
        }

        int m = n / 2;
        if(m < mpp.size()) {
            return m;
        }
        else {
            return mpp.size();
        }
    }
};