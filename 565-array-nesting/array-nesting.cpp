class Solution {
public:
    int arrayNesting(vector<int>& nums) {
        int n = nums.size();
        int ans = 1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == -1) continue;

            int curr = i;
            int count = 0;

            while (nums[curr] != -1) {
                int next = nums[curr];
                nums[curr] = -1;
                curr = next;
                count++;
            }

            ans = max(ans, count);
        }

        return ans;
    }
};