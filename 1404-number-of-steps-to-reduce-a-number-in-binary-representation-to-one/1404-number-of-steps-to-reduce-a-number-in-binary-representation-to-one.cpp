class Solution {
public:
    int numSteps(string s) {
        int n = s.length();
        int steps = 0, carry = 0, result = 0;

        for(int i = n - 1; i > 0; i--) {
            int bit = s[i] & 1;
            steps += 1 + (bit ^ carry);
            carry |= bit;
            result = steps + carry;
        }

        return result;
    }
};