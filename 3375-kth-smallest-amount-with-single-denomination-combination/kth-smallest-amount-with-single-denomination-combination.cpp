class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long ak = 1, sh = *min_element(coins.begin(), coins.end());

        auto bh = [&](long long x) {
            long long pr = 0;
            int n = coins.size();

            for (int mask = 1; mask < (1 << n); mask++) {
                long long l = 1;
                int cnt = 0;

                for (int i = 0; i < n; i++) {
                    if (mask & (1 << i)) {
                        cnt++;
                        l = lcm(l, (long long)coins[i]);
                        if (l > x) break;
                    }
                }

                if (l <= x) {
                    if (cnt & 1) pr += x / l;
                    else pr -= x / l;
                }
            }

             return pr;
        };

        long long lo = 1, hi = sh * k;

        while (lo < hi) {
            long long mid = lo + (hi - lo) / 2;

            if (bh(mid) >= k)
                hi = mid;
            else
                lo = mid + 1;
        }

        ak = lo;
        return ak;
    }
};