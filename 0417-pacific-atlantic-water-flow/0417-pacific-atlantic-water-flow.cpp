class Solution {
public:
    int m, n;
    vector<vector<bool>> pacific, atlantic;
    vector<vector<int>> dir = {{1,0},{-1,0},{0,1},{0,-1}};

    void dfs(vector<vector<int>>& heights, int i, int j, vector<vector<bool>>& ocean) {

        ocean[i][j] = true;

        for (auto &d : dir) {
            int ni = i + d[0];
            int nj = j + d[1];

            if (ni >= 0 && nj >= 0 && ni < m && nj < n &&
                !ocean[ni][nj] &&
                heights[ni][nj] >= heights[i][j]) {

                dfs(heights, ni, nj, ocean);
            }
        }
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {

        m = heights.size();
        n = heights[0].size();

        pacific.assign(m, vector<bool>(n, false));
        atlantic.assign(m, vector<bool>(n, false));

        for (int i = 0; i < m; i++) {
            dfs(heights, i, 0, pacific);
            dfs(heights, i, n - 1, atlantic);
        }

        for (int j = 0; j < n; j++) {
            dfs(heights, 0, j, pacific);
            dfs(heights, m - 1, j, atlantic);
        }

        vector<vector<int>> ans;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (pacific[i][j] && atlantic[i][j])
                    ans.push_back({i, j});
            }
        }

        return ans;
    }
};