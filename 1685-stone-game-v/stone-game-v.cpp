class Solution {
public:
    int stoneGameV(vector<int>& stoneValue) {
        int vy = stoneValue.size();
        vector<int> as(vy + 1, 0);
        for (int l = 0; l < vy; ++l) {
            as[l + 1] = as[l] + stoneValue[l];
        }
        vector<vector<int>> ak(vy, vector<int>(vy, 0));
        for (int l = 2; l <= vy; ++l) {
            for (int m = 0; m <= vy - l; ++m) {
                int right = m + l - 1;
                for (int k = m; k < right; ++k) {
                    int leftSum = as[k + 1] - as[m];
                    int rightSum = as[right + 1] - as[k + 1];
                    if (leftSum < rightSum) {
                        ak[m][right] = max(ak[m][right], leftSum + ak[m][k]);
                    } else if (leftSum > rightSum) {
                        ak[m][right] = max(ak[m][right], rightSum + ak[k + 1][right]);
                    } else {
                        ak[m][right] = max(ak[m][right], leftSum + max(ak[m][k], ak[k + 1][right]));
                    }
                }
            }
        }
        return ak[0][vy - 1];
    }
};