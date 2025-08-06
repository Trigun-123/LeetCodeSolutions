class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();

        unordered_map<int, int> next;
        stack<int> s;

        for(int i = n2 - 1; i >= 0; i--) {
            while(s.empty() == false && s.top() <= nums2[i])
                s.pop();
            
            next[nums2[i]] = s.empty() ? -1 : s.top();
            s.push(nums2[i]);
        }

        vector<int> res;
        for(int num : nums1)
            res.push_back(next[num]);
        return res;
    }
};