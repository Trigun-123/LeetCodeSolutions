class Solution {
public:
    int busyStudent(vector<int>& startTime, vector<int>& endTime, int queryTime) {
        sort(startTime.begin(),startTime.end());
        sort(endTime.begin(),endTime.end());
        int left = upper_bound(startTime.begin(),startTime.end(),queryTime) - startTime.begin();
        int right = lower_bound(endTime.begin(),endTime.end(),queryTime) - endTime.begin();
        
        return left - right;
    }
};