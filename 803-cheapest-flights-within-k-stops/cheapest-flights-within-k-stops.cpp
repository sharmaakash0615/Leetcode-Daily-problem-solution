class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) 
    {
       vector<vector<pair<int,int>>>adj(n);
       for(auto it:flights)
       {
        int u=it[0];
        int v=it[1];
        int w=it[2];
        adj[u].push_back({v,w});
       }

   vector<int>distance(n,1e9);
   priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
   pq.push({1,{0,src}});
   distance[src]=0;
   while(!pq.empty())
   {
    int num_node=pq.top().first;
    int dist=pq.top().second.first;
    int node=pq.top().second.second;
    pq.pop();

     if (num_node > k + 1) continue;

     for(auto it:adj[node])
     {
       int neigh_node=it.first;
       int wt=it.second;
       if(wt+dist< distance[neigh_node])
       {
        distance[neigh_node]=wt+dist;
        pq.push({num_node+1,{distance[neigh_node],neigh_node}});

       }
     }
   }
   
   
   if(distance[dst]==1e9) return -1;

   return distance[dst];
    }
};