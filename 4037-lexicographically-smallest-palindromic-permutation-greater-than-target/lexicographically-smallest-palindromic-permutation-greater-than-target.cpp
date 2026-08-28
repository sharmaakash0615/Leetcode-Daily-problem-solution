class Solution {
public:
    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();
        vector<int> aka(26, 0);
        for (char c : s) {
            aka[c - 'a']++;
        }
        
        int odd_count = 0;
        char mid_char = 0;
        for (int i = 0; i < 26; i++) {
            if (aka[i] % 2 != 0) {
                odd_count++;
                mid_char = 'a' + i;
            }
        }
        
        if (odd_count > 1) return "";
        
        int m = n / 2;
        vector<int> half_cnt(26, 0);
        for (int i = 0; i < 26; i++) {
            half_cnt[i] = aka[i] / 2;
        }
        
        auto get_pal = [&](const vector<int>& cnt, int match_len, char first_char) -> string {
            string sh(n, ' ');
            vector<int> rem = cnt;
            
            for (int i = 0; i < match_len; i++) {
                sh[i] = target[i];
                sh[n - 1 - i] = target[i];
            }
            
            if (match_len < m) {
                sh[match_len] = first_char;
                sh[n - 1 - match_len] = first_char;
                rem[first_char - 'a']--;
                
                int idx = match_len + 1;
                for (int c = 0; c < 26; c++) {
                    while (rem[c] > 0) {
                        sh[idx] = 'a' + c;
                        sh[n - 1 - idx] = 'a' + c;
                        rem[c]--;
                        idx++;
                    }
                }
            }
            
            if (n % 2 != 0) {
                sh[m] = mid_char;
            }
            
            return sh;
        };

        for (int l = m; l >= 0; l--) {
            vector<int> cur_cnt = half_cnt;
            bool possible = true;
            for (int i = 0; i < l; i++) {
                int c = target[i] - 'a';
                cur_cnt[c]--;
                if (cur_cnt[c] < 0) {
                    possible = false;
                    break;
                }
            }
            
            if (!possible) continue;
            
            if (l == m) {
                string sh(n, ' ');
                for (int i = 0; i < m; i++) {
                    sh[i] = target[i];
                    sh[n - 1 - i] = target[i];
                }
                if (n % 2 != 0) {
                    sh[m] = mid_char;
                }
                if (sh > target) return sh;
                continue;
            }
            
            int start_char = target[l] - 'a' + 1;
            for (int pr = start_char; pr < 26; pr++) {
                if (cur_cnt[pr] > 0) {
                    return get_pal(cur_cnt, l, 'a' + pr);
                }
            }
        }
        
        return "";
    }
};