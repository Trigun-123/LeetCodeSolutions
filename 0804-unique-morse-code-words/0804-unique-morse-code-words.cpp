class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        vector<string> store = {
            ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--",
            "-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."
        };

        unordered_set<string> transformations;

        for(auto word : words) {
            string morse = "";
            for(char c : word) {
                morse += store[c - 'a'];
            }
            transformations.insert(morse);
        }

        return transformations.size();
    }
};