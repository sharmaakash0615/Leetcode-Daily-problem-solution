class Solution {
public:
    int longestValidParentheses(string s) {
        int l = 0, m = 0, ak = 0, sh = s.length();
        
        for (int i = 0; i < sh; ++i) {
            if (s[i] == '(') {
                l++;
            } else {
                m++;
            }
            if (l == m) {
                ak = max(ak, 2 * m);
            } else if (m > l) {
                l = m = 0;
            }
        }
        
        l = m = 0;
        for (int i = sh - 1; i >= 0; --i) {
            if (s[i] == '(') {
                l++;
            } else {
                m++;
            }
            if (l == m) {
                ak = max(ak, 2 * l);
            } else if (l > m) {
                l = m = 0;
            }
        }
        
        return ak;
    }
};