class Solution {
    private:
    int maxMoney(int ind,vector<int>& arr,vector<int>& dp)
    {
        if(ind==0) return arr[0];
        if(ind<0) return 0;

        if(dp[ind]!=-1) return dp[ind];

        int pick=arr[ind]+maxMoney(ind-2, arr,dp);
        int notpick=maxMoney(ind-1, arr,dp);

        dp[ind]=max(pick,notpick);

        return dp[ind];
    }
public:
    int rob(vector<int>& nums) 
    {
        int n=nums.size();
        vector<int>dp(n,-1);
        return maxMoney(n-1 ,nums,dp);
    }
};