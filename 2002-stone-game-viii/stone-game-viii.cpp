class Solution {
public:
    int stoneGameVIII(vector<int>& stones) {
        int l = stones.size();
        vector<int> m(l);
        m[0] = stones[0];
        for (int ak = 1; ak < l; ak++) {
            m[ak] = m[ak - 1] + stones[ak];
        }
        int sh = m[l - 1];
        for (int ak = l - 2; ak >= 1; ak--) {
            sh= max(sh, m[ak] - sh);
        }
        return sh;
    }
};