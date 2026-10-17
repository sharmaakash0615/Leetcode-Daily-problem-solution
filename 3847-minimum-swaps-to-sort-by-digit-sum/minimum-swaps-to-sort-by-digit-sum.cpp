class Solution {
public:
    int minSwaps(vector<int>& nums)
     {
        int ak = nums.size();
        vector<pair<pair<int, int>, int>> pr(ak);
        for (int l = 0; l < ak; ++l) 
        {
            int val = nums[l];
            int sum = 0, temp = val;
            while (temp > 0)
             {
                sum += temp % 10;
                temp /= 10;
            }
            pr[l] = {{sum, val}, l};
        }
        sort(pr.begin(), pr.end());
        
        vector<bool> vis(ak, false);
        int sh = 0;
        for (int l = 0; l < ak; ++l)
         {
            if (vis[l] || pr[l].second == l) continue;
            int cycle_size = 0;
            int j = l;
            while (!vis[j]) {
                vis[j] = true;
                j = pr[j].second;
                cycle_size++;
            }
            if (cycle_size > 0)
             {
                sh += (cycle_size - 1);
            }
        }
        return sh;
    }
};