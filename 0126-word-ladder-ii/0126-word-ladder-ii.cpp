class Solution {
public:
    vector<vector<string>> ans;
    unordered_map<string, vector<string>> parent;

    void dfs(string word, string& beginWord, vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            return;
        }

        for (string& p : parent[word]) {
            path.push_back(p);
            dfs(p, beginWord, path);
            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(
        string beginWord,
        string endWord,
        vector<string>& wordList
    ) {

        unordered_set<string> words(
            wordList.begin(),
            wordList.end()
        );

        if (!words.count(endWord))
            return {};

        queue<string> q;
        q.push(beginWord);

        words.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int size = q.size();
            unordered_set<string> usedThisLevel;

            for (int i = 0; i < size; i++) {

                string word = q.front();
                q.pop();

                string original = word;

                for (int pos = 0; pos < word.size(); pos++) {

                    char old = word[pos];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == old)
                            continue;

                        word[pos] = c;

                        if (words.count(word)) {

                            parent[word].push_back(original);

                            if (word == endWord)
                                found = true;

                            if (usedThisLevel.insert(word).second) {
                                q.push(word);
                            }
                        }
                    }

                    word[pos] = old;
                }
            }

            // Correct: unordered_set elements are const
            for (const string& word : usedThisLevel) {
                words.erase(word);
            }
        }

        if (!found)
            return {};

        vector<string> path = {endWord};

        dfs(endWord, beginWord, path);

        return ans;
    }
};