class Solution {
public:
    int minPartitions(string n) {
        int stringSize = n.size();
        int result = 0;

        for(int i = 0; i < stringSize; i++) {
            int j = n[i] - '0';
            result = max(result, j);
        }

        return result;
    }
};