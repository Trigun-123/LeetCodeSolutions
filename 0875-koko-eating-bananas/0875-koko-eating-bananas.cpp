class Solution {
private:
    int totalHours(vector<int>& piles, int mid) {
        long long totalH = 0;
        for(int bananas : piles)
            totalH += (bananas + mid - 1) / mid;
        return totalH;
    }

public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1, high = *max_element(piles.begin(), piles.end());

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(totalHours(piles, mid) <= h)
                high = mid - 1;
            else
                low = mid + 1;
        }
        return low;
    }
};
