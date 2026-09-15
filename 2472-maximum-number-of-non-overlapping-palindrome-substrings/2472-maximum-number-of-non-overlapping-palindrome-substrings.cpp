auto init = []() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    return 0;
}();

class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        int count = 0;
        int last_end = 0;

        auto is_palindrome = [&](int l, int r) {
            while (l < r) {
                if (s[l++] != s[r--]) return false;
            }
            return true;
        };

        for (int i = 0; i <= n - k; ++i) {
            // Check odd or even length minimal palindromes starting at/after last_end
            if (i >= last_end && is_palindrome(i, i + k - 1)) {
                count++;
                last_end = i + k;
            } else if (i >= last_end && i + k < n && is_palindrome(i, i + k)) {
                count++;
                last_end = i + k + 1;
            }
        }

        return count;
    }
};