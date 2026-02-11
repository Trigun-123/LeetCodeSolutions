class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> result(n + 1);
        result[0] = first;

        for(int i = 1; i < n + 1; i++) {
            result[i] = result[i - 1] ^ encoded[i-1];
        }

        return result;
    }
};