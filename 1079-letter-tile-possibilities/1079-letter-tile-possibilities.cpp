class Solution {
private:
    int func(string& tiles, int n, vector<bool>& used) {
        int count = 0;

        for(int i = 0; i < n; i++) {
            if(used[i] || (i > 0 && tiles[i] == tiles[i - 1] && !used[i - 1])) {
                continue;
            }
            used[i] = true;
            count += 1 + func(tiles, n, used);
            used[i] = false;
        }
        
        return count;
    }

public:
    int numTilePossibilities(string tiles) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        vector<bool> used(n, false);

        return func(tiles, n, used);
    }
};