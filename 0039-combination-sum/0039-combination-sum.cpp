class Solution {
public:
    vector<vector<int>> ans;

    void backtrack(int index, vector<int>& candidates, int target, vector<int>& curr) {

        if (target == 0) {
            ans.push_back(curr);
            return;
        }

        if (target < 0 || index == candidates.size())
            return;

        // Include current element
        curr.push_back(candidates[index]);
        backtrack(index, candidates, target - candidates[index], curr);

        // Backtrack
        curr.pop_back();

        // Exclude current element
        backtrack(index + 1, candidates, target, curr);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> curr;
        backtrack(0, candidates, target, curr);
        return ans;
    }
};