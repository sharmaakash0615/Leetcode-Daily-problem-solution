class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int h = nums[0];
        int l = nums[0];

        for (int ak = 1; ak < nums.size(); ak++) {
            if (nums[ak] == nums[ak - 1] + 1)
                h += nums[ak];
            else
                 break;
        }

         l = h;

        while (find(nums.begin(), nums.end(), l) != nums.end())
            l++;

        return l;
    }
};