class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int vy = nums.size();
        unordered_map<int, int> ak;
        for (int num : nums) {
            ak[num]++;
        }

        int as = -1;

        if (k == vy) {
            for (int num : nums) {
                as = max(as, num);
            }
        } else if (k == 1) {
            for (auto& [val, count] : ak) {
                if (count == 1) {
                    as = max(as, val);
                }
            }
        } else {
            if (ak[nums[0]] == 1) {
                as = max(as, nums[0]);
            }
            if (ak[nums[vy - 1]] == 1) {
                as = max(as, nums[vy - 1]);
            }
        }

        return as;
    }
};