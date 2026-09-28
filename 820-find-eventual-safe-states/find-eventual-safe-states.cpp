class Solution {
    private:
    bool dfs(int node,vector<int>& vis,vector<int>& pathvis,vector<int>& check,vector<vector<int>>& graph)
    {
        vis[node]=1;
        pathvis[node]=1;
        check[node]=0;
        for(auto it:graph[node])
        {
            if(!vis[it])
            {
              
                if(dfs(it,vis,pathvis,check,graph)==true)
                {
                    check[node]=0;
                    return true;
                }
            }
                else if(pathvis[it])
                {
                      check[node]=0;
                      return true;
                }
            
           
        }
       
             check[node]=1;
            pathvis[node]=0;
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    int n=graph.size();
    vector<int>vis(n,0);
    vector<int>pathvis(n,0);
    vector<int>safenode;
    vector<int>check(n,0);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            dfs(i,vis,pathvis,check,graph);
        }
    }
     for(int i=0;i<n;i++)
     {
        if(check[i]==1)
        {
          safenode.push_back(i); 
        }
     }

     return safenode;
    }
};