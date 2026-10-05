class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
      int n=graph.size();
      vector<vector<int>>revgraph(n);
      for(int i=0;i<n;i++)  
      {
        for(auto it:graph[i])
        {
          revgraph[it].push_back(i);
        }
      } 
      vector<int>indegree(n,0);
      for(int i=0;i<n;i++)  
      {
        for(auto it: revgraph[i])
        {
            indegree[it]++;
        }
      } 
     queue<int>q;
      for(int i=0;i<n;i++)
      {
        if( indegree[i]==0)
        {
            q.push(i);
        }
      }
      vector<int>safenode;
      while(!q.empty())
      {
        int node=q.front();
        q.pop();
        safenode.push_back(node);
        for(auto it: revgraph[node])
        {
            indegree[it]--; 
            if( indegree[it]==0)
           {
               q.push(it);
            }
        }
      }

      sort(safenode.begin(),safenode.end());

      return safenode;
    }
};