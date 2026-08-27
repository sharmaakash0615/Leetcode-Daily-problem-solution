class Solution {
public:
    string lexGreaterPermutation(string s, string target) {
        int n = s.size();
        vector<int> freq(26, 0);

        for (char c : s)
            freq[c - 'a']++;

        string ans;

        int i = 0;

        while (i < n && freq[target[i] - 'a'] > 0) {
            ans += target[i];
            freq[target[i] - 'a']--;
            i++;
        }

        if (i < n) {
            int x = target[i] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = ans;
                    result += char('a' + c);
                    freq[c]--;

                    for (int k = 0; k < 26; k++)
                        result += string(freq[k], char('a' + k));

                    return result;
                }
            }
        }

        for (int pos = ans.size() - 1; pos >= 0; pos--) {
            freq[ans.back() - 'a']++;
            ans.pop_back();

            int x = target[pos] - 'a';

            for (int c = x + 1; c < 26; c++) {
                if (freq[c] > 0) {
                    string result = ans;
                    result += char('a' + c);
                    freq[c]--;

                    for (int k = 0; k < 26; k++)
                        result += string(freq[k], char('a' + k));

                    return result;
                }
            }
        }

        return "";
    }
};