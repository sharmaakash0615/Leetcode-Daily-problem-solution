class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int ak = 0;
        
        for(int a = 0; a < 10; a++) {
            for(int b = 0; b < 10; b++) {
                for(int gj = 0; gj < 10; gj++) {
                    if(a == 0 || gj % 2 != 0)
                        continue;
                    
                    vector<int> cnt(10, 0);
                    for(int x : digits)
                        cnt[x]++;
                    
                    cnt[a]--;
                    cnt[b]--;
                    cnt[gj]--;
                    
                    if(cnt[a] >= 0 && cnt[b] >= 0 && cnt[gj] >= 0)
                        ak++;
                }
            }
        }
        
        return ak;
    }
};