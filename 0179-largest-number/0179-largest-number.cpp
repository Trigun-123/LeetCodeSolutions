class Solution {
private:    
    static bool compare(string s, string t) { 
        return (s + t) > (t + s); 
    }

public:
    string largestNumber(vector<int>& nums) {
        int n = nums.size();
        vector<string> s;

        for(int i = 0; i < n; i++) {
            s.push_back(to_string(nums[i]));
        }

        sort(s.begin(), s.end(), compare);

        if(s[0] == "0") { 
            return "0";
        }

        string result = "";
        for(auto it : s) {
            result.append(it);
        }

        return result;
    }
};