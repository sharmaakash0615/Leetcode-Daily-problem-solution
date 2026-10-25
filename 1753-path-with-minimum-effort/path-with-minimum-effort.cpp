class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights)
 {
  int n=heights.size();
  int m=heights[0].size();

  vector<vector<int>>diff(n,vector<int>(m,1e9));
  priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
  diff[0][0]=0;
  pq.push({0,{0,0}});
  while(!pq.empty())
  {
    int  difference=pq.top().first;
    int row=pq.top().second.first;
    int col=pq.top().second.second;
    pq.pop();

    if(row==n-1 && col==m-1) return difference;
    
    int delrow[]={-1,0,+1,0};
    int delcol[]={0,+1,0,-1};

    for(int i=0;i<4;i++)
    {
        int nrow=row+delrow[i];
        int ncol=col+delcol[i];

     if(nrow>=0 && nrow<n && ncol>=0 && ncol<m)
     {
        int diff1=abs(heights[row][col]-heights[nrow][ncol]);
        int efforts=max( difference,diff1);
        if( efforts<diff[nrow][ncol])
        {
          diff[nrow][ncol]=efforts;  
          pq.push({diff[nrow][ncol],{nrow,ncol}});
        }

     }
    }
  }

  return 0;
   
 }
};