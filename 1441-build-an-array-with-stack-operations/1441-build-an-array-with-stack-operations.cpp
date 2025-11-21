class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int m = target.size();
        vector<string> result;
        int index = 0; 

        for(int i = 1; i <= n && index < m; i++) {
            result.push_back("Push"); 

            if(i == target[index])
                index++; 
            else
                result.push_back("Pop"); 
        }

        return result;
    }
};
