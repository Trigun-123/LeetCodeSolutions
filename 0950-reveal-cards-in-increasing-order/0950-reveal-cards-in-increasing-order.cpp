class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        int n = deck.size();
        int i = 0, j = 0;
        vector<int> result(n, 0);
        sort(deck.begin(), deck.end());
        bool skip = false;

        while(i < n) {
            if(result[j] == 0) {
                if(skip == false) {
                    result[j] = deck[i];
                    i++;
                }
                skip = !skip;
            }
            j = (j + 1) % n;
        }

        return result;
    }
};
