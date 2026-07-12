class Solution {
public:

    // Check if Koko can finish all bananas with speed k
    bool canFinish(vector<int>& piles, int h, int k) {

        long long hours = 0;

        for (int bananas : piles) {

            hours += (bananas + k - 1) / k;

            // Already exceeded allowed hours
            if (hours > h)
                return false;
        }

        return true;
    }

    int minEatingSpeed(vector<int>& piles, int h) {

        int left = 1;
        int right = *max_element(piles.begin(), piles.end());

        while (left < right) {

            int mid = left + (right - left) / 2;

            if (canFinish(piles, h, mid))
                right = mid;     
            else
                left = mid + 1;   
        }

        return left;
    }
};