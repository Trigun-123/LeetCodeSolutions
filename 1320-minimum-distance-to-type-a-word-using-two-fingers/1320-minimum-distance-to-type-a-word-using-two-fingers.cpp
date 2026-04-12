class Solution {
public:
    int solve(int firstPos, int secondPos) {
        return abs(firstPos / 6 - secondPos / 6) + abs(firstPos % 6 - secondPos % 6);
    }

    int minimumDistance(string word) {
        int length = word.size();
        vector<int> dpState(26), nextDpState(26);

        for(int index = 1; index < length; index++) {
            int prevChar = word[index - 1] - 'A';
            int currChar = word[index] - 'A';

            for(int finger = 0; finger < 26; finger++) {
                nextDpState[finger] = dpState[finger] + solve(prevChar, currChar);
            }

            for(int finger = 0; finger < 26; finger++) {
                nextDpState[prevChar] = min(nextDpState[prevChar], dpState[finger] + solve(finger, currChar));
            }

            dpState = nextDpState;
        }

        return *min_element(dpState.begin(), dpState.end());
    }
};