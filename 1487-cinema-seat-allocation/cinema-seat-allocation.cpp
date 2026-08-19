class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {
        unordered_map<int, int> ak;

        for (auto &x : reservedSeats) {
            if (x[1] >= 2 && x[1] <= 9)
                ak[x[0]] |= (1 << x[1]);
        }

        long long ans = 2LL * (n - ak.size());

         int left = (1 << 2) | (1 << 3) | (1 << 4) | (1 << 5);
        int mid = (1 << 4) | (1 << 5) | (1 << 6) | (1 << 7);
        int right = (1 << 6) | (1 << 7) | (1 << 8) | (1 << 9);

        for (auto &p : ak) {
            int mask = p.second;

             bool a = (mask & left) == 0;
            bool b = (mask & mid) == 0;
            bool c = (mask & right) == 0;

            if (a && c)
                ans += 2;
            else if (a || b || c)
                ans += 1;
        }

        return ans;
    }
};