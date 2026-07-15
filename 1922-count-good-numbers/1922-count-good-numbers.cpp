class Solution {
public:
    static const int MOD = 1000000007;

    static long long power(long long x, long long n, long long mod) {

        if (n == 0)
            return 1;

        long long half = power(x, n / 2, mod);
        long long result = (half * half) % mod;

        if (n % 2 == 1)
            result = (result * x) % mod;
            
        return result;
    }

    int countGoodNumbers(long long n) {
        long long even_count = (n + 1) / 2;
        long long odd_count = n / 2;
        return (power(5, even_count, MOD) * power(4, odd_count, MOD)) % MOD;
    }
};