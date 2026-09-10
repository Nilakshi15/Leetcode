class Solution {
public:
    bool isPossible(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> need;

        // Count frequency of every number
        for (int num : nums) {
            freq[num]++;
        }

        for (int num : nums) {
            // Already used
            if (freq[num] == 0)
                continue;

            // Try to extend an existing subsequence
            if (need[num - 1] > 0) {
                freq[num]--;
                need[num - 1]--;
                need[num]++;
            }

            // Otherwise create a new subsequence of length 3
            else if (freq[num + 1] > 0 && freq[num + 2] > 0) {
                freq[num]--;
                freq[num + 1]--;
                freq[num + 2]--;

                need[num + 2]++;
            }

            // Cannot use this number
            else {
                return false;
            }
        }

        return true;
    }
};