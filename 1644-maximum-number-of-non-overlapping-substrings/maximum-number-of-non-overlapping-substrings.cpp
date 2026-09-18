class Solution {
public:
    vector<string> maxNumOfSubstrings(string s) {
        int n = s.size();
        vector<int> a(26, n), l(26, -1);

        for (int ak = 0; ak < n; ak++) {
            int sh = s[ak] - 'a';
            a[sh] = min(a[sh], ak);
            l[sh] = ak;
        }

        vector<pair<int, int>> sh;

        for (int ak = 0; ak < 26; ak++) {
            if (l[ak] == -1) continue;

            int x = a[ak];
            int y = l[ak];
            bool ok = true;

            for (int i = x; i <= y; i++) {
                int c = s[i] - 'a';

                if (a[c] < x) {
                    ok = false;
                    break;
                }

                y = max(y, l[c]);
            }

            if (ok)
                sh.push_back({x, y});
        }

        sort(sh.begin(), sh.end(), [](auto &ak, auto &l) {
            return ak.second < l.second;
        });

        vector<string> ans;
        int last = -1;

        for (auto &[ak, l] : sh) {
            if (ak > last) {
                ans.push_back(s.substr(ak, l - ak + 1));
                last = l;
            }
        }

        return ans;
    }
};