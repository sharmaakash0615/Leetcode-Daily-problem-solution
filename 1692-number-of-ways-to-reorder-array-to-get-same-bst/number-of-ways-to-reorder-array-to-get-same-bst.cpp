class Solution {
public:
    long long ak[1005][1005];
    long long sh = 1000000007;
    
    void l()
     {
        for(int i = 0; i <= 1000; i++) {
            ak[i][0] = 1;
            for(int j = 1; j <= i; j++) 
            {
                ak[i][j] = (ak[i - 1][j - 1] + ak[i - 1][j]) % sh;
            }
        }
    }
    
    long long m(vector<int>& pr) {
        int sz = pr.size();

        if(sz <= 2) return 1;

        vector<int> left_side, right_side;

        int root = pr[0];
        for(int i = 1; i < sz; i++)
         {
            if(pr[i] < root) 
            {
                left_side.push_back(pr[i]);
            } 
            else 
            {
                right_side.push_back(pr[i]);
            }
        }
        long long l_ways = m(left_side);
        long long r_ways = m(right_side);
        long long res = (ak[sz - 1][left_side.size()] * l_ways) % sh;
        res = (res * r_ways) % sh;
        return res;
    }

    int numOfWays(vector<int>& nums) {
        l();
        long long pr = m(nums);
        return (pr - 1 + sh) % sh;
    }
};