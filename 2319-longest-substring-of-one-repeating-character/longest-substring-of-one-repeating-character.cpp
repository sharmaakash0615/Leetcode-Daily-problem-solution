class Solution {
    struct Node {
        int mx, pref, suff;
        char lc, rc;
    };

    vector<Node> tree;

    void merge(int i, int l, int r, int mid) {
        int left = 2 * i;
        int right = 2 * i + 1;
        int lenL = mid - l + 1;
        int lenR = r - mid;

        tree[i].lc = tree[left].lc;
        tree[i].rc = tree[right].rc;

        tree[i].pref = tree[left].pref;
        if (tree[left].pref == lenL && tree[left].rc == tree[right].lc) {
            tree[i].pref += tree[right].pref;
        }

        tree[i].suff = tree[right].suff;
        if (tree[right].suff == lenR && tree[left].rc == tree[right].lc) {
            tree[i].suff += tree[left].suff;
        }

        tree[i].mx = max(tree[left].mx, tree[right].mx);
        if (tree[left].rc == tree[right].lc) {
            tree[i].mx = max(tree[i].mx, tree[left].suff + tree[right].pref);
        }
    }

    void build(int i, int l, int r, const string& s) {
        if (l == r) {
            tree[i] = {1, 1, 1, s[l], s[l]};
            return;
        }
        int mid = l + (r - l) / 2;
        build(2 * i, l, mid, s);
        build(2 * i + 1, mid + 1, r, s);
        merge(i, l, r, mid);
    }

    void update(int i, int l, int r, int idx, char ch) {
        if (l == r) {
            tree[i].lc = tree[i].rc = ch;
            return;
        }
        int mid = l + (r - l) / 2;
        if (idx <= mid) {
            update(2 * i, l, mid, idx, ch);
        } else {
            update(2 * i + 1, mid + 1, r, idx, ch);
        }
        merge(i, l, r, mid);
    }

public:
    vector<int> longestRepeating(string s, string queryCharacters, vector<int>& queryIndices) {
        int n = s.length();
        int k = queryIndices.size();
        tree.resize(4 * n);

        build(1, 0, n - 1, s);

        vector<int> ans(k);
        for (int i = 0; i < k; ++i) {
            update(1, 0, n - 1, queryIndices[i], queryCharacters[i]);
            ans[i] = tree[1].mx;
        }

        return ans;
    }
};