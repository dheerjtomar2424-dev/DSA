class Solution {
public:
    string simplifyPath(string path) {

        vector<string> dirs;
        string current;

        for (int i = 0; i <= path.size(); i++) {

            if (i == path.size() || path[i] == '/') {

                if (current == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                }
                else if (!current.empty() && current != ".") {
                    dirs.push_back(current);
                }

                current.clear();
            }
            else {
                current += path[i];
            }
        }

        string ans;

        for (string &dir : dirs) {
            ans += '/';
            ans += dir;
        }

        return ans.empty() ? "/" : ans;
    }
};