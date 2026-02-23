class Solution {
public:
    bool hasAllCodes(string s, int k) {
        int n = s.size();
        unordered_set<string> st;

        for(int i = 0; i + k <= n; i++) {
            st.insert(s.substr(i, k));
        }

        int m = st.size();

        return m == pow(2, k);
    }
};