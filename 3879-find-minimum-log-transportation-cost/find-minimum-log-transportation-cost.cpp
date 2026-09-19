class Solution {
public:
    long long minCuttingCost(int n, int m, int k) {
        long long cost = 0;
        if (n <= k && m <= k) {
            return cost;
        }

        if (n > k) {
            long long rem_n = n - k;
            cost += (rem_n * k);
        }
        if (m > k) {
            long long rem_m = m - k;
            cost += (rem_m * k);
        }

        return cost;
    }
};