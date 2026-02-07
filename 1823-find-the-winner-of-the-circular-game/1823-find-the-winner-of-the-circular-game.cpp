class Solution {
private:
    void func(int n, int k, vector<int>& result, int current) {
        if(result.size() == 1) {
            return;
        }
      
        cut += k - 1;

        if(currenr >= result.size()) {
            currentsult.size();
        }

        result.erase(result.begin() + current);

        func(n, k, result, current);
    }

public:
    int findTheWinner(int n, int k) {
        vector<int>result(n, 0);

        for(int i = 0; i < n; i++) {
            result[i] = i + 1;
        }

        func(n, k, result, 0);

        return result[0];
    }
};