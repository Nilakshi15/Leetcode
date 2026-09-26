class Solution {
public:
    int maxRotateFunction(std::vector<int>& nums) {
        int n = nums.size();
        long long totalSum = 0;
        long long currentF = 0;

        // Calculate F(0) and the total sum of array
        for (int i = 0; i < n; ++i) {
            totalSum += nums[i];
            currentF += (long long)i * nums[i];
        }

        long long maxF = currentF;

        // Compute F(1) to F(n-1) using the O(1) transition formula
        for (int i = n - 1; i > 0; --i) {
            currentF = currentF + totalSum - (long long)n * nums[i];
            maxF = std::max(maxF, currentF);
        }

        return maxF;
    }
};