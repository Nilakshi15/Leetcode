class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int write = 0;  // index where the next non-zero should go

        // First, write all non-zero values at the front
        for (int i = 0; i < n; i++) {
            
            if (nums[i] != 0) {
                nums[write++] = nums[i];
            }
        }

        // Then fill the rest with zeros
        for (int j = write; j < n; j++) {
            nums[j] = 0;
        }
    }
};
