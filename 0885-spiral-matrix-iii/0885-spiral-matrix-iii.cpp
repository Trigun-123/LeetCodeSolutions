class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> dir = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};    
        vector<vector<int>> res = {{rStart, cStart}};
        int steps = 0, d = 0;
        
        while(res.size() < rows * cols) {
            if(d == 0 || d == 2) {
                steps++;
            }    
            
            for(int i = 0; i < steps; i++) {
                rStart += dir[d][0];
                cStart += dir[d][1];

                if(rStart >= 0 && rStart < rows && cStart >= 0 && cStart < cols) {
                    res.push_back({rStart, cStart});
                }
                if(res.size() == rows * cols) {
                    return res;
                }    
            }
            d = (d + 1) % 4;
        }
        
        return res;
    }
};