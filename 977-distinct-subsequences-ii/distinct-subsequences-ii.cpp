class Solution {
public:
    int distinctSubseqII(string s) {
        long long l = 0;
        long long ak[26] = {};
        long long sh = 0;
        long long mn = 1000000007;

        for(char c : s) {
            int x = c - 'a';

            l = (sh + 1) % mn;
            sh = (sh + l - ak[x] + mn) % mn;
            ak[x] = l;
        }

        return sh;
    }
};