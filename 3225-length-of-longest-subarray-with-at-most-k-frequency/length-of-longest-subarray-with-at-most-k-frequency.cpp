class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int l = 0, h = 0, sh = 0;
        unordered_map<int, int> vy;

        while (h < n) {
            vy[nums[h]]++;

            while (vy[nums[h]] > k) {
                vy[nums[l]]--;
                l++;
            }

            sh = max(sh, h - l + 1);
            h++;
        }

        return sh;
    }
};