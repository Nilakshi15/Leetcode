class WordDictionary {
public:

    struct Node {
        Node* child[26];
        bool end;

        Node() {
            for (int i = 0; i < 26; i++)
                child[i] = NULL;
            end = false;
        }
    };

    Node* root;

    WordDictionary() {
        root = new Node();
    }

    void addWord(string word) {

        Node* curr = root;

        for (char c : word) {
            int idx = c - 'a';

            if (curr->child[idx] == NULL)
                curr->child[idx] = new Node();

            curr = curr->child[idx];
        }

        curr->end = true;
    }

    bool dfs(string &word, int pos, Node* node) {

        if (node == NULL)
            return false;

        if (pos == word.size())
            return node->end;

        if (word[pos] == '.') {

            for (int i = 0; i < 26; i++) {
                if (dfs(word, pos + 1, node->child[i]))
                    return true;
            }

            return false;
        }

        return dfs(word, pos + 1, node->child[word[pos] - 'a']);
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};