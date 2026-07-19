class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int>& nums, vector<int>& curr) {
        ans.push_back(curr);

        for (int i = index; i < nums.size(); i++) {
            curr.push_back(nums[i]);
            backtrack(i + 1, nums, curr);
            curr.pop_back();
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> curr;
        backtrack(0, nums, curr);
        return ans;
    }
};