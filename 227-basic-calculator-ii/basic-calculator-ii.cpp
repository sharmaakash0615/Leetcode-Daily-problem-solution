class Solution {
public:
    int calculate(string s) {
        int ak = 0;
        int l = 0;
        char m = '+';
        vector<int> sh;

        for (int i = 0; i < s.length(); ++i) {
            char c = s[i];

            if (isdigit(c)) {
                ak = ak * 10 + (c - '0');
            }

            if ((!isdigit(c) && c != ' ') || i == s.length() - 1) {
                if (m == '+') {
                    sh.push_back(ak);
                } else if (m == '-') {
                    sh.push_back(-ak);
                } else if (m == '*') {
                    int top = sh.back();
                    sh.pop_back();
                    sh.push_back(top * ak);
                } else if (m == '/') {
                    int top = sh.back();
                    sh.pop_back();
                    sh.push_back(top / ak);
                }
                m = c;
                ak = 0;
            }
        }

        for (int val : sh) {
            l += val;
        }

        return l;
    }
};