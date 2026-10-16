class Solution {
public:
    int sumCounts(vector<int>& nums) {
        long long MOD = 1e9 + 7;
        int n = nums.size();
        
        vector<long long> tree_sum(4 * n, 0);

        vector<long long> tree_cnt(4 * n, 0);

        vector<long long> lazy(4 * n, 0);
        
        auto propagate = [&](auto& self, int node, int l, int r) -> void {
            if (lazy[node] != 0) 
            {
             int mid = l + (r - l) / 2;

                long long val = lazy[node];
                
                int left_child = 2 * node;

                long long len_left = mid - l + 1;

                tree_sum[left_child] = (tree_sum[left_child] + 2 * tree_cnt[left_child] * val + val * val * len_left) % MOD;

                tree_cnt[left_child] = (tree_cnt[left_child] + val * len_left) % MOD;
                lazy[left_child] = (lazy[left_child] + val) % MOD;
                
                int right_child = 2 * node + 1;

            long long len_right = r - mid;
                tree_sum[right_child] = (tree_sum[right_child] + 2 * tree_cnt[right_child] * val + val * val * len_right) % MOD;

                tree_cnt[right_child] = (tree_cnt[right_child] + val * len_right) % MOD;
                lazy[right_child] = (lazy[right_child] + val) % MOD;
                
                lazy[node] = 0;
            }
        };

        function<void(int, int, int, int, int, long long)> update = [&](int node, int l, int r, int ql, int qr, long long val) {
            if (ql <= l && r <= qr) 
            {
                long long count = r - l + 1;
                tree_sum[node] = (tree_sum[node] + 2 * tree_cnt[node] * val + val * val * count) % MOD;
                tree_cnt[node] = (tree_cnt[node] + val * count) % MOD;
                lazy[node] = (lazy[node] + val) % MOD;
                return;
            }
            propagate(propagate, node, l, r);
            int mid = l + (r - l) / 2;
            if (ql <= mid) {
                update(2 * node, l, mid, ql, qr, val);
            }
            if (qr > mid) {
                update(2 * node + 1, mid + 1, r, ql, qr, val);
            }
            tree_sum[node] = (tree_sum[2 * node] + tree_sum[2 * node + 1]) % MOD;
            tree_cnt[node] = (tree_cnt[2 * node] + tree_cnt[2 * node + 1]) % MOD;
        };

        unordered_map<int, int> gj;
        long long ak = 0;

        for (int j = 0; j < n; ++j) {
            int i = 0;
            if (gj.find(nums[j]) != gj.end()) {
                i = gj[nums[j]] + 1;
            }
            gj[nums[j]] = j;
            
            update(1, 0, n - 1, i, j, 1);
            ak = (ak + tree_sum[1]) % MOD;
        }

        return ak;
    }
};