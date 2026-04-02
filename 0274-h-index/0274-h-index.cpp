class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        vector<int> citationBuckets(n + 1, 0);

        for(auto it : citations) {
            citationBuckets[min(it, n)]++;
        }

        int cumulativePapers = 0;

        for(int i = n; i >= 0; i--) {
            cumulativePapers += citationBuckets[i];
            if(cumulativePapers >= i) {
                return i;
            }
        }

        return 0;        
    }
};