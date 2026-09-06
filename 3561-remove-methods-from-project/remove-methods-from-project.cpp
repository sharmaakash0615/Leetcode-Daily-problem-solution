class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adj(n);

        for (auto &e : invocations) {
            adj[e[0]].push_back(e[1]);
        }

        vector<int> suspicious(n, 0);
        queue<int> q;

        suspicious[k] = 1;
        q.push(k);

        while (!q.empty()) {
            int u = q.front();
            q.pop();

            for (int v : adj[u]) {
                if (!suspicious[v]) {
                    suspicious[v] = 1;
                    q.push(v);
                }
            }
        }

        for (auto &e : invocations) {
            if (!suspicious[e[0]] && suspicious[e[1]]) {
                vector<int> ans;
                for (int i = 0; i < n; i++) {
                    ans.push_back(i);
                }
                return ans;
            }
        }

        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (!suspicious[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};