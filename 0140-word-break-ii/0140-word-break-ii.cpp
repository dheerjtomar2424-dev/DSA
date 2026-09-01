class Solution {
public:
    unordered_set<string> dict;
    unordered_map<int, vector<string>> memo;

    vector<string> dfs(string& s, int start) {

        if (memo.count(start))
            return memo[start];

        vector<string> result;

        if (start == s.size()) {
            result.push_back("");
            return result;
        }

        for (int end = start; end < s.size(); end++) {

            string word = s.substr(start, end - start + 1);

            if (!dict.count(word))
                continue;

            vector<string> next = dfs(s, end + 1);

            for (string& sentence : next) {

                if (sentence.empty())
                    result.push_back(word);
                else
                    result.push_back(word + " " + sentence);
            }
        }

        return memo[start] = result;
    }

    vector<string> wordBreak(string s, vector<string>& wordDict) {

        dict = unordered_set<string>(
            wordDict.begin(),
            wordDict.end()
        );

        return dfs(s, 0);
    }
};