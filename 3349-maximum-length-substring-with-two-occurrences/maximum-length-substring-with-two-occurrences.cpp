class Solution {
public:
    int maximumLengthSubstring(string s) {
      int ak = 0, pr = 0, ans = 0;
        vector<int> cnt(26, 0);

        for (int i = 0; i < s.size(); i++) {
            cnt[s[i] - 'a']++;

            while (cnt[s[i] - 'a'] > 2) {
                cnt[s[ak] - 'a']--;
                ak++;
            }

            ans = max(ans, i - ak + 1);
        }

        return ans;  
    }
};