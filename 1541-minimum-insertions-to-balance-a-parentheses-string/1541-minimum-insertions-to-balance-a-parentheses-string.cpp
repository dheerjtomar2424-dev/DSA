class Solution {
public:
    int minInsertions(string s) {
        int insertions = 0;
        int openCount = 0;
        int n = s.length();

        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                openCount++;
            } else { // s[i] == ')'
                // Check if the next character is also ')'
                if (i + 1 < n && s[i + 1] == ')') {
                    i++; // Consume the second ')'
                } else {
                    // Only a single ')' was found, need to insert one ')'
                    insertions++;
                }

                // Match with an open '(' if available
                if (openCount > 0) {
                    openCount--;
                } else {
                    // No open '(' available, need to insert one '('
                    insertions++;
                }
            }
        }

        // Each remaining open '(' needs two closing '))'
        insertions += openCount * 2;

        return insertions;
    }
};