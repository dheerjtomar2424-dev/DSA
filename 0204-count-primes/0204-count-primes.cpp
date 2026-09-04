class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        int count = n / 2; // 2 + all odd numbers
        vector<bool> composite(n / 2, false);

        for (int i = 3; 1LL * i * i < n; i += 2) {
            if (!composite[i / 2]) {
                for (int j = i * i; j < n; j += 2 * i) {
                    if (!composite[j / 2]) {
                        composite[j / 2] = true;
                        --count;
                    }
                }
            }
        }

        return count;
    }
};