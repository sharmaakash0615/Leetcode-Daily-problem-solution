class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int ak = 0, as = 0, vy = 0;
        
        for (int x : stones) {
            if (x % 3 == 0) ak++;
            else if (x % 3 == 1) as++;
            else vy++;
        }

        if (ak % 2 == 0) {
             return as > 0 && vy > 0;
        }

         return abs(as - vy) > 2;
    }
};