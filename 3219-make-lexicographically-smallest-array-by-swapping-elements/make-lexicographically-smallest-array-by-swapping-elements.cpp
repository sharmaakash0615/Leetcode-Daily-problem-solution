class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int ak = nums.size();
        vector<pair<int, int>> sh(ak);
        for (int i = 0; i < ak; ++i) {
            sh[i] = {nums[i], i};
        }
        sort(sh.begin(), sh.end());

        vector<vector<pair<int, int>>> rm;
        rm.push_back({sh[0]});

        for (int i = 1; i < ak; ++i) {
            if (sh[i].first - sh[i - 1].first <= limit) {
                rm.back().push_back(sh[i]);
            } else {
                rm.push_back({sh[i]});
            }
        }

        vector<int> ans(ak);
        for (const auto& group : rm) {
            vector<int> indices;
            for (const auto& p : group) {
                indices.push_back(p.second);
            }
            sort(indices.begin(), indices.end());
            for (size_t i = 0; i < group.size(); ++i) {
                ans[indices[i]] = group[i].first;
            }
        }

        return ans;
    }
};