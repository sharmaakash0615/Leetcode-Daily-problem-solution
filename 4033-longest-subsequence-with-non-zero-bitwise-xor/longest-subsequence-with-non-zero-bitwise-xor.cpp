class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
       int ak = 0;
        bool vy = false;
        int as = nums.size();
        
        for (int x : nums) {
            ak ^= x;
            if (x != 0) {
                vy = true;
            }
        }
        
        if (ak != 0) {
            return as;
        }
        if (vy) {
         return as - 1;
        }
        return 0; 
    }
};