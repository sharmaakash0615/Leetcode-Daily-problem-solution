class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int ak = 0;
        int sh = nums.size();
        
        for (int l = 0; l < sh; l++) {
            if (nums[l] != val) {
                int m = nums[l];
                nums[ak] = m;
                ak++;
            }
        }
        
        return ak;
    }
};