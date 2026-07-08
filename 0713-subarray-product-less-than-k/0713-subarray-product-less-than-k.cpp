class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {

        // No positive product can be less than 1
        if (k <= 1)
            return 0;

        int left = 0;
        long long product = 1;
        int ans = 0;

        for (int right = 0; right < nums.size(); right++) {

            // Include current element
            product *= nums[right];

            // Shrink window until product < k
            while (product >= k) {
                product /= nums[left];
                left++;
            }

            // Count all valid subarrays ending at right
            ans += right - left + 1;
        }

        return ans;
    }
};