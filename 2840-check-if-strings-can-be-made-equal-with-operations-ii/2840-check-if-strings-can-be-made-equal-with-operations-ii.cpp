class Solution {
public:
    bool checkStrings(string s1, string s2) {
        int n = s1.size();
        string s1Eve = "", s1Od = "", s2Eve = "", s2Od = "";
     
        for(int i = 0; i < n; i++) {
            if(i % 2 == 0) {
                s1Eve += s1[i];
                s2Eve += s2[i];
            } 
            else {
                s1Od += s1[i];
                s2Od += s2[i];
            }
        }
        
        sort(s1Eve.begin(), s1Eve.end());
        sort(s2Eve.begin(), s2Eve.end());
        sort(s1Od.begin(), s1Od.end());
        sort(s2Od.begin(), s2Od.end());
        
        return (s1Eve == s2Eve) && (s1Od == s2Od);
    }
};