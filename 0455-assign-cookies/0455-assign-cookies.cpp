class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        int n = g.size();
        int m = s.size();
        int left = 0, right = 0;
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());

        while(left < n && right < m) {
            if(s[right] >= g[left])
                left++;
            right++;
        }
        return left;
    }
};