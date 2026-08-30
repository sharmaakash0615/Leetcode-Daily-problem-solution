class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 1;

        int l = 0;
        int m = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[l]) l = i;
            if (nums[i] > nums[m]) m = i;
        }

        int ak = min(l, m);
        int sh = max(l, m);

        return min({sh + 1, n - ak, (ak + 1) + (n - sh)});
    }
};