class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
     int V=numCourses;
     vector<vector<int>>adj(V);
     
     for(auto it:prerequisites)  
     {
        int u=it[0];
        int v=it[1];
        adj[v].push_back(u);
     }

  vector<int>indgree(V,0);
  for(int i=0;i<V;i++)
  {
      for(auto it:adj[i])
      {
          indgree[it]++;
      }
  }
queue<int>q;  
for(int i=0;i<V;i++)
{
    if(indgree[i]==0)
    {
        q.push(i);
    }
}
vector<int>bfs;

  while(!q.empty())
  {
    int node=q.front();
    q.pop();
    bfs.push_back(node);
    for(auto it:adj[node])
    {
      indgree[it]--;
      if( indgree[it]==0)
      {
          q.push(it);
      }
    }
  }
  int cnt=bfs.size();
  if(cnt==V)
  return true;

  return false;


    }
};