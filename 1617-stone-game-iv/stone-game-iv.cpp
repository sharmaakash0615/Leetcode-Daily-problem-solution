class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> l(n + 1, false);
        
        for (int g = 1; g <= n; g++) {
            for (int ak = 1; ak * ak <= g; ak++) {
                if (!l[g - ak * ak]) {
                    l[g] = true;
                    break;
                }
            }
        }
        
        return l[n];
    }
};