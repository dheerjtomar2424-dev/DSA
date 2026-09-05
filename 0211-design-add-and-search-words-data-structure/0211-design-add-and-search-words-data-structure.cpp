class WordDictionary {
    struct Node {
        Node* child[26]{};
        bool end = false;
    };

    Node* root = new Node();

    bool dfs(const string& word, int i, Node* node) {
        if (i == word.size())
            return node->end;

        if (word[i] == '.') {
            for (Node* next : node->child) {
                if (next && dfs(word, i + 1, next))
                    return true;
            }
            return false;
        }

        Node* next = node->child[word[i] - 'a'];

        return next && dfs(word, i + 1, next);
    }

public:
    WordDictionary() {}

    void addWord(string word) {
        Node* cur = root;

        for (char c : word) {
            int x = c - 'a';

            if (!cur->child[x])
                cur->child[x] = new Node();

            cur = cur->child[x];
        }

        cur->end = true;
    }

    bool search(string word) {
        return dfs(word, 0, root);
    }
};