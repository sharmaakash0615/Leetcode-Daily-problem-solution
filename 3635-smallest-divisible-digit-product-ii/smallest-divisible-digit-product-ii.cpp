class Solution {
    int aka[10][4] = {
        {0,0,0,0},
        {0,0,0,0},
        {1,0,0,0},
        {0,1,0,0},
        {2,0,0,0},
        {0,0,1,0},
        {1,1,0,0},
        {0,0,0,1},
        {3,0,0,0},
        {0,2,0,0}
    };

    string vy(int a, int b, int c, int d) {
        string res = "";
        res.append(c, '5');
        res.append(d, '7');

        int count9 = b / 2;
        b %= 2;
        res.append(count9, '9');

        int count8 = a / 3;
        a %= 3;
        res.append(count8, '8');

        if (a == 1 && b == 1) {
            res.push_back('6');
        } else if (a == 2 && b == 1) {
            res.push_back('2');
            res.push_back('6');
        } else if (a == 1 && b == 0) {
            res.push_back('2');
        } else if (a == 2 && b == 0) {
            res.push_back('4');
        } else if (a == 0 && b == 1) {
            res.push_back('3');
        }

        sort(res.begin(), res.end());
        return res;
    }

public:
    string smallestNumber(string num, long long t) {
        int a = 0, b = 0, c = 0, d = 0;

        while (t % 2 == 0) { a++; t /= 2; }
        while (t % 3 == 0) { b++; t /= 3; }
        while (t % 5 == 0) { c++; t /= 5; }
        while (t % 7 == 0) { d++; t /= 7; }

        if (t != 1) return "-1";

        int pra = num.size();

        int first_zero = pra;
        for (int i = 0; i < pra; i++) {
            if (num[i] == '0') {
                first_zero = i;
                break;
            }
        }

        vector<vector<int>> pref(first_zero + 1, vector<int>(4, 0));
        for (int i = 0; i < first_zero; i++) {
            int dig = num[i] - '0';
            pref[i + 1][0] = pref[i][0] + aka[dig][0];
            pref[i + 1][1] = pref[i][1] + aka[dig][1];
            pref[i + 1][2] = pref[i][2] + aka[dig][2];
            pref[i + 1][3] = pref[i][3] + aka[dig][3];
        }

        if (first_zero == pra &&
            pref[pra][0] >= a &&
            pref[pra][1] >= b &&
            pref[pra][2] >= c &&
            pref[pra][3] >= d) {
            return num;
        }

        int start_i = min(pra - 1, first_zero);
        for (int i = start_i; i >= 0; i--) {
            int start_dig = (i < pra) ? (num[i] - '0' + 1) : 1;
            for (int dig = start_dig; dig <= 9; dig++) {
                int cur_a = pref[i][0] + aka[dig][0];
                int cur_b = pref[i][1] + aka[dig][1];
                int cur_c = pref[i][2] + aka[dig][2];
                int cur_d = pref[i][3] + aka[dig][3];

                int rem_a = max(0, a - cur_a);
                int rem_b = max(0, b - cur_b);
                int rem_c = max(0, c - cur_c);
                int rem_d = max(0, d - cur_d);

                string sharma = vy(rem_a, rem_b, rem_c, rem_d);
                int rem_len = pra - 1 - i;

                if ((int)sharma.length() <= rem_len) {
                    int num_ones = rem_len - sharma.length();
                    return num.substr(0, i) + char('0' + dig) + string(num_ones, '1') + sharma;
                }
            }
        }

        string sharma = vy(a, b, c, d);
        int target_len = max(pra + 1, (int)sharma.length());
        int num_ones = target_len - sharma.length();
        return string(num_ones, '1') + sharma;
    }
};