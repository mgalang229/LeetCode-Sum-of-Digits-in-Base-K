class Solution {
    int get_pow(int a, int b) {
        int res = 1;
        while (b > 0) {
            if (b & 1) {
                res *= a;
            }
            a *= a;
            b >>= 1;
        }
        return res;
    }
public:
    int sumBase(int n, int k) {
        int sum = 0;
        int limit = log10(n) / log10(k) + 1;
        for (int i = limit; i >= 0; i--) {
            int cur = get_pow(k, i), cnt = 0;
            while (n >= cur) {
                n -= cur;
                cnt++;
            }
            if (cnt > 0) {
                sum += cnt;
            }
        }
        return sum;
    }
};
