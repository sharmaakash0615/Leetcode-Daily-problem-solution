class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int aka = piles.size();
        
        vector<int> sha(aka + 1, 0);
        for (int i = aka - 1; i >= 0; --i) {
            sha[i] = sha[i + 1] + piles[i];
        }
        
        vector<vector<int>> vy(aka + 1, vector<int>(aka + 1, 0));
        
        for (int i = aka - 1; i >= 0; --i) {
            for (int m = 1; m <= aka; ++m) {
                if (i + 2 * m >= aka) {
                    vy[i][m] = sha[i];
                } else {
                    for (int x = 1; x <= 2 * m; ++x) {
                        vy[i][m] = max(vy[i][m], sha[i] - vy[i + x][max(m, x)]);
                    }
                }
            }
        }
        
        return vy[0][1];
    }
};