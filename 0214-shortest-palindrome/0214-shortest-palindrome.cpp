class Solution {
private:
    vector<int> computeLPS(string s) {
        int n = s.size(); 
        vector<int> LPS(n, 0);
        int i = 1, j = 0;
    
        while(i < n) {
            if(s[i] == s[j]) {
                LPS[i] = j+1;
                i++, j++;
            }
            else {
                while(j > 0 && s[i] != s[j])
                    j = LPS[j-1];
                
                if(s[i] == s[j]) {
                    LPS[i] = j+1;
                    j++;
                }
                i++;
            }
        }
        return LPS; 
    }
    
public:
    string shortestPalindrome(string s) {
		string rev = s;
		reverse(rev.begin(), rev.end()); 

		string str = s + '$' + rev; 
		vector<int> lps = computeLPS(str); 
		int ans = s.size() - lps.back(); 
		string toAdd = rev.substr(0, ans); 
		return toAdd + s; 
	}
};