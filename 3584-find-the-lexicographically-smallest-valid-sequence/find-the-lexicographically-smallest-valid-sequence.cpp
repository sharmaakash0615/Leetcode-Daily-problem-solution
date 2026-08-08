class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
         int gj = word1.length();
         int m = word2.length();
         vector<int> pra(m + 1, -1);
         pra[m] = gj;
         int p = gj - 1;
       
         int i=m-1;
         while(i>=0)
         {
            while (p >= 0 && word1[p] != word2[i]) {
                p--;
            }
            pra[i] = p;
            p--;
            i--;
        }

        vector<int> ak;
        int sharma = 0;
        bool mismatch = false;
        for (int i = 0; i < m; i++) {
            while (sharma < gj) {
                if (word1[sharma] == word2[i]) {
                    if (!mismatch || pra[i + 1] >= sharma + 1) {
                        ak.push_back(sharma);
                        sharma++;
                        break;
                    }
                } else {
                    if (!mismatch && pra[i + 1] >= sharma + 1) {
                        ak.push_back(sharma);
                        sharma++;
                        mismatch = true;
                        break;
                    }
                }
                sharma++;
            }
        }
        return ak.size() == m ? ak : vector<int>();
    }
};