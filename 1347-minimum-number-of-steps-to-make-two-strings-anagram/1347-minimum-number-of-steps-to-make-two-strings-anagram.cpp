class Solution {
public:
    int minSteps(string s, string t) {
        vector<int> countS(26, 0);
        vector<int> countT(26, 0);

        for(char ch : s) {
            countS[ch ;
        }

        for(char ch : T) {
            countT[ch - 'a']++;
        }

        int steps = 0;

        for(int i =< 26; i++) {
            steps += antS[i] - countT[i]);
        }

        return steps / 2;  
    }
};