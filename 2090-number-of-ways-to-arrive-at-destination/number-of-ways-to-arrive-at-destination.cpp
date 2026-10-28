// class Solution {
// public:
//     int countPaths(int n, vector<vector<int>>& roads)
//   {
//     vector<vector<pair<int,int>>>adj(n);
//     for(auto it:roads)
//     {
//         int u=it[0];
//         int v=it[1];
//         int w=it[2];
//         adj[u].push_back({v,w});
//         adj[v].push_back({u,w});
//     }
//     int mod=1e9 + 7;
//     vector<int>ways(n,0);
//     vector<int>distance(n,1e9);
//     //  vector<long long> distance(n,LLONG_MAX);
//     ways[0]=1;
//     distance[0]=0;
//     priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
//     pq.push({0,0});
//     while(!pq.empty())
//     {
//         int node=pq.top().second;
//         int dist=pq.top().first;
//         pq.pop();

        

       

//         for(auto it:adj[node])
//         {
//             int nnode=it.first;
//             int wt=it.second;

//             if(wt+dist<distance[nnode])
//             {
//                distance[nnode]= wt+dist;
//                ways[nnode]=ways[node];
//                pq.push({ distance[nnode],nnode});
//             }

//             else if(wt+dist==distance[nnode])
//             {
//                 ways[nnode]=(ways[node]+ways[nnode])%mod;
//             }
//         }
//     }
  
  
//    return (ways[n-1])%mod;

//  }
// };



class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads)
    {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : roads)
        {
            int u = it[0];
            int v = it[1];
            int w = it[2];

            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }

        int mod = 1e9 + 7;

        vector<int> ways(n,0);
        vector<long long> distance(n,LLONG_MAX);

        ways[0] = 1;
        distance[0] = 0;

        priority_queue<pair<long long,int>,
                       vector<pair<long long,int>>,
                       greater<pair<long long,int>>> pq;

        pq.push({0,0});

        while(!pq.empty())
        {
            long long dist = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if(dist > distance[node])
                continue;

            for(auto it : adj[node])
            {
                int nnode = it.first;
                int wt = it.second;

                if(wt + dist < distance[nnode])
                {
                    distance[nnode] = wt + dist;
                    ways[nnode] = ways[node];

                    pq.push({distance[nnode],nnode});
                }
                else if(wt + dist == distance[nnode])
                {
                    ways[nnode] = (ways[node] + ways[nnode]) % mod;
                }
            }
        }

        return ways[n-1];
    }
};
