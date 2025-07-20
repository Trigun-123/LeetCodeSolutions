class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int left = 0, right = n - 1;
        int sum = 0;

        while(left < k) {
            sum += cardPoints[left];
            left++;
        }

        left = k - 1;
        int maxScore = sum;

        while(left>=0) {
            sum -= cardPoints[left];
            sum += cardPoints[right];
            maxScore = max(maxScore, sum);
            left--;
            right--;
        }
        return maxScore;
    }
};