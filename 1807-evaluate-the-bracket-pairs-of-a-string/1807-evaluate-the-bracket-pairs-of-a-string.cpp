class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        // Store knowledge pairs in a hash map for O(1) lookup
        unordered_map<string, string> dict;
        for (const auto& pair : knowledge) {
            dict[pair[0]] = pair[1];
        }

        string result = "";
        int n = s.length();
        
        for (int i = 0; i < n; ++i) {
            if (s[i] == '(') {
                string key = "";
                // Extract the key inside the brackets
                while (++i < n && s[i] != ')') {
                    key += s[i];
                }
                // Check if key exists in the map
                if (dict.count(key)) {
                    result += dict[key];
                } else {
                    result += '?';
                }
            } else {
                result += s[i];
            }
        }

        return result;
    }
};