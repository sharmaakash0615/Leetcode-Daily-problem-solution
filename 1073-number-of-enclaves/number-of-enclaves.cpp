// class Solution {
//     private:
//     void dfs(vector<vector<int>>& grid,vector<vector<int>>& vis,pair<int,int>node)
//     {
//        int n= grid.size();
//        int m=grid[0].size();
//        int delrow[]={-1,0,+1,0};
//        int delcol[]={0,+1,0,-1};
//        int row=node.first;
//        int col=node.second;
//         vis[row][col]=1;
//         for(int i=0;i<4;i++)
//         {
//             int nrow=row+delrow[i];
//             int ncol=col+delcol[i];
//         if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && grid[nrow][ncol] == 1 && vis[nrow][ncol]==0)
//         {
//                 dfs(grid,vis,{nrow,ncol});
//         }
//         }

//     }
// public:
//     int numEnclaves(vector<vector<int>>& grid) {
//     int n= grid.size();
//     int m=grid[0].size();
//     vector<vector<int>>vis(n,vector<int>(m,0));
//     for(int i=0;i<m;i++)
//     {
      
//         if(grid[0][i]==1)
//         {
//             pair<int,int>node={0,i};
//             dfs(grid,vis,node);
//         }
//     }
//     for(int i=0;i<n;i++)
//     {
      
//         if(grid[i][0]==1)
//         {
//             pair<int,int>node={i,0};
//             dfs(grid,vis,node);
//         }
//     }

//     for(int i=0;i<m;i++)
//     {

      
//         if(grid[n-1][i]==1)
//         {
//             pair<int,int>node={n-1,i};
//             dfs(grid,vis,node);
//         }
//     }

//     for(int i=0;i<n;i++)
//     {
      
//         if(grid[i][m-1]==1)
//         {
//             pair<int,int>node={m-1,i};
//             dfs(grid,vis,node);
//         }
//     }

// int cnt=0;
//   for(int i=0;i<n;i++)
//   {
//     for(int j=0;j<m;j++)
//     {
//       if( grid[i][j]==1 && vis[i][j]==0)
//       {
//          cnt++;
//       }
//     }
//   }
    
//     return cnt;
//     }
// };


class Solution {
    private:
    void dfs(vector<vector<int>>& grid, vector<vector<int>>& vis, pair<int,int> node)
    {
        int n = grid.size();
        int m = grid[0].size();

        int delrow[] = {-1,0,1,0};
        int delcol[] = {0,1,0,-1};

        int row = node.first;
        int col = node.second;

        vis[row][col] = 1;

        for(int i=0;i<4;i++)
        {
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];

            if(nrow >= 0 && nrow < n &&
               ncol >= 0 && ncol < m &&
               grid[nrow][ncol] == 1 &&
               vis[nrow][ncol] == 0)
            {
                dfs(grid,vis,{nrow,ncol});
            }
        }
    }

public:
    int numEnclaves(vector<vector<int>>& grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> vis(n,vector<int>(m,0));

        // Top row
        for(int i=0;i<m;i++)
        {
            if(grid[0][i] == 1)
            {
                dfs(grid,vis,{0,i});
            }
        }

        // Left column
        for(int i=0;i<n;i++)
        {
            if(grid[i][0] == 1)
            {
                dfs(grid,vis,{i,0});
            }
        }

        // Bottom row
        for(int i=0;i<m;i++)
        {
            if(grid[n-1][i] == 1)
            {
                dfs(grid,vis,{n-1,i});
            }
        }

        // Right column
        for(int i=0;i<n;i++)
        {
            if(grid[i][m-1] == 1)
            {
                dfs(grid,vis,{i,m-1});
            }
        }

        int cnt = 0;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j] == 1 && vis[i][j] == 0)
                {
                    cnt++;
                }
            }
        }

        return cnt;
    }
};