class Solution {
public:
    string makeLargestSpecial(string s) {
        if(urn s;
        }

        int n = 
        vector<string> result;
        int count = 0; 

        for(int i = 0, j = 0; i < n; i++) {
            count += s[i] == '1' ? 1 : -1;
            if(count == 0) {
                result.push_back("1" + makeLargestSpecial(s.substr(j + 1, i - j - 1)) + "0");
                j = i + 1;
            }
        }
        sort(result.begin(), ans.end(), greater<string>{});

        return accumulate(result.begin(), result.end(), ""s);
    }
};