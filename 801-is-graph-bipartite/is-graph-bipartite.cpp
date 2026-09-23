// class Solution {
//     private:
//     bool bfsMulti(int start,vector<int>& vis,vector<vector<int>>& graph)
//     {
//      queue<int>q;
//      q.push(start);
//      vis[start]=0;
//      while(!q.empty())
//      {
//         int node=q.front();
//         q.pop();
       
//         for(auto it:graph[node])
//         {
           
//             if(vis[it]==-1)
//             {
//             vis[it]=!vis[node];
//             q.push(it);
            
//             }
//             else if(vis[it]==vis[node])
//             {
//                 return false;
//             }
           
//         }
//      }
//      return true;
//     }
// public:
//     bool isBipartite(vector<vector<int>>& graph) {
//     int n=graph.size();
//     int m=graph[0].size();
//     vector<int>vis(n,-1);
    
//     for(int i=0;i<n;i++)
//     {
//         if(vis[i]==-1)
//         {
//             if(bfsMulti(i,vis,graph)==false)
//             return false;

//         }
       
//     }
    // return true;
//     }
// };


class Solution {
    private:
    bool dfsMulti(int start,vector<int>& vis,vector<vector<int>>& graph,int prev)
    {
      vis[start]=prev;
     
    for(auto it:graph[start])
    {
        if(vis[it]==-1)
        {
        if(dfsMulti(it,vis,graph,!prev)==false)
          return false;
        }
        else if(vis[it]==vis[start])
        {
           return false;
        }
        
     
    }
    return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
    int n=graph.size();
    int m=graph[0].size();
    vector<int>vis(n,-1);
    
    for(int i=0;i<n;i++)
    {
        if(vis[i]==-1)
        {
            if(dfsMulti(i,vis,graph,0)==false)
            return false;
            
        }
       
    }
    return true;
    }
};