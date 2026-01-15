class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size();
        vector<int> vec;
        int i = 0, j = n;

        for(auto it : s) {
            if(it == 'I') {
                vec.push_back(i++);
            }    
            else {
                vec.push_back(j--);
            }    
        }
        vec.push_back(i);

        return vec;
    }
};