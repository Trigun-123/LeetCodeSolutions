class Solution {
public:
    string getHappyString(int n, int k) {
        if(k > (3 << (n - 1))) {
            return ""; 
        }    
        
        queue<string> q;
        q.push("");
        
        while(k) {
            string current = q.front();
            q.pop();
            
            for(char c = 'a'; c <= 'c'; c++) {
                if(current.empty() || current.back() != c) {
                    q.push(current + c);
                    if(current.size() + 1 == n) {
                        k--;
                    }    
                }
                if(k == 0) {
                    break;
                }    
            }
        }

        return q.back();
    }
};