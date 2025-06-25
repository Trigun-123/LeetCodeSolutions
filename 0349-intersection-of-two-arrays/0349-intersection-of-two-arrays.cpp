class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n1 = nums1.size();
        int n2 = nums2.size();
        int i = 0;
        int j = 0;
        set<int> st;
        vector<int>result;

        while(i < n1 && j < n2) {
            if(nums1[i] < nums2[j]) 
                i++;
            else if(nums2[j] < nums1[i])
                j++;
            else { 
                st.insert(nums1[i]);
                i++;
                j++;
            }
        }

        for(auto it : st)
            result.push_back(it);

        return result;
    }
};