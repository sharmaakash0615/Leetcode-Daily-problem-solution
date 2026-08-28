class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        int ak = 1;
        
        for (int l = n - 1; l >= 0; l--) {
            int m = digits[l] + ak;
            digits[l] = m % 10;
            ak = m / 10;
        }
        
        if (ak > 0) {
            vector<int> sh(n + 1, 0);
            sh[0] = ak;
            for (int l = 0; l < n; l++) {
                sh[l + 1] = digits[l];
            }
            return sh;
        }
        
        return digits;
    }
};