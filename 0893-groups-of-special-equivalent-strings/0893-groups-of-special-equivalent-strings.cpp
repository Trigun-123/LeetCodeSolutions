class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        unordered_set<string> st;

        for(int i = 0; i < n; i++) {
            string even = "";
            string odd = "";

            for(int j = 0; j < words[i].size(); j++) {
                if(j % 2 == 1) {
                    odd += words[i][j];
                }    
                else {
                    even += words[i][j];
                }    
            }

            sort(even.begin(),even.end());
            sort(odd.begin(),odd.end());
            st.insert(even + odd);
        }

        return st.size();
    }
};