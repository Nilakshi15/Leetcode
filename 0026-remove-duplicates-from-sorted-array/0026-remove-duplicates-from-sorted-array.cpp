class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
       if (nums.empty()) return 0;

        int i = 0; // slow pointer for unique values
        for (int j = 1; j < nums.size(); ++j) {

            if (nums[j] != nums[i]) {
                ++i;
                nums[i] = nums[j]; // overwrite with unique element
            }
        }

        return i + 1; 
    }
};