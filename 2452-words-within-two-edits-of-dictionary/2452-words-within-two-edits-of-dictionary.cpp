class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        int n = queries[0].size();
        vector<string> result;

        for(auto it : queries) {
            for(auto i : dictionary) {
                int difference = 0;
                for(int index = 0; index < n; index++) {
                    if(it[index] != i[index]) {
                        difference++;
                    }
                    if(difference > 2) {
                        break;
                    }    
                }
                if(difference <= 2) {
                    result.push_back(it);
                    break;
                }
            }
        }

        return result;
    }
};