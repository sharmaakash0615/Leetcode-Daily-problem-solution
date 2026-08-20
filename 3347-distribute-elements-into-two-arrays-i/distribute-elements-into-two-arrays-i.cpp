class Solution {
public:
    vector<int> resultArray(vector<int>& aka) {
        vector<int> as1, as2;

        as1.push_back(aka[0]);
        as2.push_back(aka[1]);

        for (int i = 2; i < aka.size(); i++) {
            if (as1.back() > as2.back()) {
                as1.push_back(aka[i]);
            } else {
                as2.push_back(aka[i]);
            }
        }

       
        for (int x : as2) {
            as1.push_back(x);
        }

         return as1;
    }
};