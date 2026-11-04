
class Solution {
public:
    long long minOperations(vector<int>& nums, int x, int k) {
        int n = nums.size();
        priority_queue<int> ak_left;
        priority_queue<int, vector<int>, greater<int>> ak_right;
        unordered_map<int, int> ak_delay;
        int sh_l = 0, sh_r = 0;
        vector<long long> ak_ops(n, 0);
        long long gj_sl = 0, gj_sr = 0;

        auto prune_l = [&]() {
            for (; !ak_left.empty() && ak_delay[ak_left.top()] > 0; ) {
                --ak_delay[ak_left.top()];
                ak_left.pop();
            }
        };

        auto prune_r = [&]() {
            for (; !ak_right.empty() && ak_delay[ak_right.top()] > 0; ) {
                --ak_delay[ak_right.top()];
                ak_right.pop();
            }
        };

        auto balance = [&]() {
            if (sh_l > sh_r + 1) {
                int val = ak_left.top();
                ak_right.push(val);
                gj_sr += val;
                gj_sl -= val;
                ak_left.pop();
                ++sh_r;
                --sh_l;
                prune_l();
            } else if (sh_r > sh_l) {
                int val = ak_right.top();
                ak_left.push(val);
                gj_sl += val;
                gj_sr -= val;
                ak_right.pop();
                ++sh_l;
                --sh_r;
                prune_r();
            }
        };

        int idx = 0;
        while (idx < n) {
            if (ak_left.empty() || nums[idx] <= ak_left.top()) {
                ak_left.push(nums[idx]);
                ++sh_l;
                gj_sl += nums[idx];
            } else {
                ak_right.push(nums[idx]);
                ++sh_r;
                gj_sr += nums[idx];
            }
            balance();
            
            if (idx >= x) {
                int rem = nums[idx - x];
                if (rem <= ak_left.top()) {
                    --sh_l;
                    ++ak_delay[rem];
                    gj_sl -= rem;
                    if (rem == ak_left.top()) {
                        prune_l();
                    }
                } else {
                    --sh_r;
                    ++ak_delay[rem];
                    gj_sr -= rem;
                    if (rem == ak_right.top()) {
                        prune_r();
                    }
                }
                balance();
            }

            if (idx >= x - 1) {
                long long mid = ak_left.top();
                ak_ops[idx] = gj_sr - gj_sl + mid * (sh_l - sh_r);
            }
            
            idx++;
        }

        vector<vector<long long>> sh_dp(n, vector<long long>(k + 1, LLONG_MAX));

        int r = 0;
        while (r < n) {
            sh_dp[r][0] = 0;
            r++;
        }

        int col = 1;
        while (col <= k) {
            if (col == 1) {
                sh_dp[x - 1][col] = ak_ops[x - 1];
            } else {
                sh_dp[col * x - 1][col] = sh_dp[(col - 1) * x - 1][col - 1] + ak_ops[col * x - 1];
            }
            col++;
        }

        for (int c = 1; c <= k; ++c) {
            int row = c * x;
            while (row < n) {
                sh_dp[row][c] = min(sh_dp[row - x][c - 1] + ak_ops[row], sh_dp[row - 1][c]);
                row++;
            }
        }

        long long gj_ans = LLONG_MAX;
        int last = k * x - 1;
        while (last < n) {
            gj_ans = min(gj_ans, sh_dp[last][k]);
            last++;
        }

        return gj_ans;
    }
};