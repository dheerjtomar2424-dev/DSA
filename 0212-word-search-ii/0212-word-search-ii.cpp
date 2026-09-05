class Solution {
    struct Node {
        Node* child[26]{};
        string word;
    };

    Node* root = new Node();
    vector<string> ans;
    int m, n;

    void dfs(vector<vector<char>>& board, int r, int c, Node* node) {
        char ch = board[r][c];

        if (ch == '#') return;

        Node* next = node->child[ch - 'a'];
        if (!next) return;

        if (!next->word.empty()) {
            ans.push_back(next->word);
            next->word.clear(); // avoid duplicates
        }

        board[r][c] = '#';

        if (r > 0) dfs(board, r - 1, c, next);
        if (r + 1 < m) dfs(board, r + 1, c, next);
        if (c > 0) dfs(board, r, c - 1, next);
        if (c + 1 < n) dfs(board, r, c + 1, next);

        board[r][c] = ch;
    }

public:
    vector<string> findWords(vector<vector<char>>& board,
                             vector<string>& words) {
        m = board.size();
        n = board[0].size();

        // Build Trie
        for (const string& word : words) {
            Node* cur = root;

            for (char ch : word) {
                int x = ch - 'a';

                if (!cur->child[x])
                    cur->child[x] = new Node();

                cur = cur->child[x];
            }

            cur->word = word;
        }

        // DFS from every cell
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                dfs(board, i, j, root);
            }
        }

        return ans;
    }
};