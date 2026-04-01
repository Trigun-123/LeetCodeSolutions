class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        sort(order.begin(), order.end(), [&](int a,int b) { 
            return positions[a] < positions[b]; 
        });
        vector<bool> alive(n,true);
        vector<int> s;

        for(int it : order) {
            if(directions[it] == 'R') {
                s.push_back(it);
            }
            else {
                while(!s.empty()) {
                    int top = s.back();
                    if(healths[top] < healths[it]) {
                        alive[top] = false;
                        s.pop_back();
                        healths[it]--;
                    }
                    else if(healths[top] > healths[it]) {
                        alive[it] = false;
                        healths[top]--;
                        break;
                    }
                    else {
                        alive[top] = false;
                        alive[it] = false;
                        s.pop_back();
                        break;
                    }
                }
            }
        }

        vector<int> result;

        for(int i = 0; i < n; i++) {
            if(alive[i]) {
                result.push_back(healths[i]);
            }
        }    

        return result;
    }
};