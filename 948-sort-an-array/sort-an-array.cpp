class Solution {
public:
    void merge(vector<int>& a, int l, int m, int r) {
        int i = l, j = m + 1, k = 0;
        vector<int> b(r - l + 1);

        while (i <= m && j <= r) {
            if (a[i] <= a[j])
                b[k++] = a[i++];
            else
                b[k++] = a[j++];
        }

        while (i <= m)
            b[k++] = a[i++];

        while (j <= r)
            b[k++] = a[j++];

        for (int i = l; i <= r; i++)
            a[i] = b[i - l];
    }

    void solve(vector<int>& a, int l, int r) {
        if (l >= r)
            return;

        int m = l + (r - l) / 2;

        solve(a, l, m);
        solve(a, m + 1, r);
        merge(a, l, m, r);
    }

    vector<int> sortArray(vector<int>& nums) {
        solve(nums, 0, nums.size() - 1);
        return nums;
    }
};