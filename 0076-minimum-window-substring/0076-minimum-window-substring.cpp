class Solution {
public:
    string minWindow(string s, string t) {

        if (s.size() < t.size())
            return "";

        int need[128] = {0};

        for (char c : t)
            need[c]++;

        int left = 0;
        int start = 0;
        int minLen = INT_MAX;
        int remaining = t.size();

        for (int right = 0; right < s.size(); right++) {

            if (need[s[right]] > 0)
                remaining--;

            need[s[right]]--;

            while (remaining == 0) {

                int len = right - left + 1;

                if (len < minLen) {
                    minLen = len;
                    start = left;
                }

                need[s[left]]++;

                if (need[s[left]] > 0)
                    remaining++;

                left++;
            }
        }

        return minLen == INT_MAX
               ? ""
               : s.substr(start, minLen);
    }
};