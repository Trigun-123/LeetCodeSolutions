class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.size(), m = goal.size();
        
        if(n != m) {
            return false;
        }
            
        return (s + s).find(goal) != string::npos;
    }
};