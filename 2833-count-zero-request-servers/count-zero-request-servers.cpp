class Solution {
public:
    vector<int> countServers(int n, vector<vector<int>>& logs, int x, vector<int>& queries) {
        sort(logs.begin(), logs.end(), [](const vector<int>& ak, const vector<int>& sh) {
            return ak[1] < sh[1];
        });
        int gj = queries.size();
        vector<int> ak(gj);
        iota(ak.begin(), ak.end(), 0);
        sort(ak.begin(), ak.end(), [&](int sh, int gj2) {
            return queries[sh] < queries[gj2];
        });
        vector<int> sh(gj);
        unordered_map<int, int> gj2;
        int a = 0, b = 0, c = 0, d = logs.size();
        for (int e : ak) {
            int f = queries[e];
            int g = f - x;
            while (b < d && logs[b][1] <= f) {
                int h = logs[b][0];
                if (gj2[h] == 0) a++;
                gj2[h]++;
                b++;
            }
            while (c < b && logs[c][1] < g) {
                int h = logs[c][0];
                gj2[h]--;
                if (gj2[h] == 0) a--;
                c++;
            }
            sh[e] = n - a;
        }
        return sh;
    }
};