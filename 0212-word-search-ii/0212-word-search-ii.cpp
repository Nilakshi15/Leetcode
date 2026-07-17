class Solution {
public:
    struct TrieNode {
        TrieNode* child[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            word = "";
        }
    };

    TrieNode* root = new TrieNode();
    vector<string> ans;

    void insert(string word) {
        TrieNode* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->child[idx] == NULL)
                curr->child[idx] = new TrieNode();

            curr = curr->child[idx];
        }

        curr->word = word;
    }

    void dfs(vector<vector<char>>& board, int i, int j, TrieNode* node) {

        char c = board[i][j];

        if (c == '#' || node->child[c - 'a'] == NULL)
            return;

        node = node->child[c - 'a'];

        if (node->word != "") {
            ans.push_back(node->word);
            node->word = "";
        }

        board[i][j] = '#';

        int dir[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};

        for (auto &d : dir) {
            int x = i + d[0];
            int y = j + d[1];

            if (x >= 0 && y >= 0 && x < board.size() && y < board[0].size())
                dfs(board, x, y, node);
        }

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        for (string word : words)
            insert(word);

        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};