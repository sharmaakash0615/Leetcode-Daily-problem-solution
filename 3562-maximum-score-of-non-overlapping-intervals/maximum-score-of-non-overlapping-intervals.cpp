class Solution {
public:
    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        int n = intervals.size();

        vector<array<long long, 3>> a;
        for (int i = 0; i < n; i++) {
            a.push_back({intervals[i][0], intervals[i][1], i});
        }

        sort(a.begin(), a.end());

        vector<int> nxt(n);
        for (int i = 0; i < n; i++) {
            int l = i + 1, r = n;
            while (l < r) {
                int m = l + (r - l) / 2;
                if (a[m][0] > a[i][1])
                    r = m;
                else
                    l = m + 1;
            }
            nxt[i] = l;
        }

        vector<vector<pair<long long, vector<int>>>> dp(
            n + 1, vector<pair<long long, vector<int>>>(5)
        );

        auto better = [](pair<long long, vector<int>> x,
                         pair<long long, vector<int>> y) {
            if (x.first != y.first)
                return x.first > y.first;

            return x.second < y.second;
        };

        for (int i = n - 1; i >= 0; i--) {
            for (int k = 1; k <= 4; k++) {
                dp[i][k] = dp[i + 1][k];

                auto cur = dp[nxt[i]][k - 1];
                cur.first += intervals[a[i][2]][2];
                cur.second.push_back(a[i][2]);

                sort(cur.second.begin(), cur.second.end());

                if (better(cur, dp[i][k]))
                    dp[i][k] = cur;
            }
        }

        return dp[0][4].second;
    }
};