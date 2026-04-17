class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        unordered_map<char, int> mpp;

        for(auto it : magazine) {
            mpp[it]++;
        }

        for(auto it : ransomNote) {
            if(mpp[it] <= 0) {
                return false;
            }
            mpp[it]--;
        }

        return true;
    }
};