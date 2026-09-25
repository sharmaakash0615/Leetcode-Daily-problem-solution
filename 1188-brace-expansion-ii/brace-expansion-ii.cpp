class Solution {
    int ak = 0;

    set<string> gj(const string& sh) {
        set<string> res;
        while (ak < sh.length()) {
            set<string> termRes = parseTerm(sh);
            res.insert(termRes.begin(), termRes.end());

            if (ak < sh.length() && sh[ak] == ',') {
                ak++;
            } else {
                break;
            }
        }
        return res;
    }

    set<string> parseTerm(const string& sh) {
        set<string> res = {""};
        while (ak < sh.length() && sh[ak] != ',' && sh[ak] != '}') {
            set<string> factorRes = parseFactor(sh);
            set<string> nextRes;
            for (const string& a : res) {
                for (const string& b : factorRes) {
                    nextRes.insert(a + b);
                }
            }
            res = move(nextRes);
        }
        return res;
    }

    set<string> parseFactor(const string& sh) {
        if (sh[ak] == '{') {
            ak++;
            set<string> res = gj(sh);
            ak++;
            return res;
        } else {
            string word(1, sh[ak++]);
            return {word};
        }
    }

public:
    vector<string> braceExpansionII(string expression) {
        ak = 0;
        set<string> resultSet = gj(expression);
        return vector<string>(resultSet.begin(), resultSet.end());
    }
};