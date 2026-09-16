class Solution {
public:
    int numberOfSets(int n, int k) {
        long long MOD = 1e9 + 7;
        int total = n + k - 1;
        int r = 2 * k;

        if (r > total) return 0;
        if (r > total - r) r = total - r;

        long long num = 1, den = 1;
        for (int i = 1; i <= r; ++i) {
            num = (num * (total - i + 1)) % MOD;
            den = (den * i) % MOD;
        }

        // Modular inverse using Fermat's Little Theorem: den^(MOD - 2) % MOD
        long long inv = power(den, MOD - 2, MOD);
        return (num * inv) % MOD;
    }

private:
    long long power(long long base, long long exp, long long mod) {
        long long res = 1;
        base %= mod;
        while (exp > 0) {
            if (exp & 1) res = (res * base) % mod;
            base = (base * base) % mod;
            exp >>= 1;
        }
        return res;
    }
};