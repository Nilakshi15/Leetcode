class Solution {
public:
    bool canPartition(std::vector<int>& nums) {
        int totalSum = std::accumulate(nums.begin(), nums.end(), 0);
        
        // If total sum is odd, it can't be split into two equal integer subsets
        if (totalSum % 2 != 0) {
            return false;
        }
        
        int target = totalSum / 2;
        
        // Max sum target is 200 * 100 / 2 = 10000
        std::bitset<10001> dp;
        dp[0] = 1; // Base case: sum 0 is always achievable with an empty set
        
        for (int num : nums) {
            dp |= (dp << num);
        }
        
        return dp[target];
    }
};