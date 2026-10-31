class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) 
    {
        vector<vector<int>>dist(n,vector<int>(n,1e8));
        for(auto it:edges)
        {
            int u=it[0];
            int v=it[1];
            int w=it[2];
            dist[u][v]=w;
            dist[v][u]=w;
        }
     for(int i=0;i<n;i++)
     {
        dist[i][i]=0;
     }
    for(int k = 0; k < n; k++)
        {
            for(int i = 0; i < n; i++)
            {
                for(int j = 0; j < n; j++)
                {
                    if(dist[i][k] != 1e8 && dist[k][j] != 1e8)
                    {
                        dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
                    }
                }
            }
        }
        
        int city=-1;
        int countmax=n;

        for(int i=0;i<n;i++)
        {
            int cnt=0;

            for(int j=0;j<n;j++)
            {
                if(dist[i][j]<=distanceThreshold)
                {
                    cnt++;
                }
            }
            if(cnt<=countmax)
            {
                countmax=cnt;
                if(i>city)
                {
                    city=i;
                }
            }
        }
     return city;
    }
};