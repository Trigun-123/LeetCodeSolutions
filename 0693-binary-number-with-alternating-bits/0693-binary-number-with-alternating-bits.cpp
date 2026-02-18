class Solution {
public:
    bool hasAlternatingBits(int n) {
        unsigned int alternatingCheck = n ^ (n >> 1);
        return (alternatingCheck & (alternatingCheck + 1)) == 0;
    }
};