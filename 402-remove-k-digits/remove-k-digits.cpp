class Solution {
public:
    string removeKdigits(string num, int k) {
        string sh = "";
        
        for (char c : num) {
            while (!sh.empty() && k > 0 && sh.back() > c) {
                sh.pop_back();
                k--;
            }
            sh.push_back(c);
        }
        
        while (k > 0 && !sh.empty()) {
            sh.pop_back();
            k--;
        }
        
        int l = 0;
        int m = sh.length();
        while (l < m && sh[l] == '0') {
            l++;
        }
        
        string ak = sh.substr(l);
        return ak.empty() ? "0" : ak;
    }
};