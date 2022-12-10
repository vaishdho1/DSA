/*
Implementation of Djikstra using priority queue.
Here we may have to run the !pq.empty() loop a few times
as we cant update in a priority queue but only insert.
In a set we update so the loop is run exactly V times.
But there is an extra cost of erase which can add a log(V^2) factor.
The time gain is not very sinificant and it depends on the way the graph and its edge weights.

TC: O(E*log(V))
*/
vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dis(V,1e9);
        dis[S] = 0;
        pq.push({0,S});
        
        while(!pq.empty())
        {
            
            int node = pq.top().second;
            int d = pq.top().first;
            pq.pop();
            for(auto edge:adj[node])
            {
                if(dis[edge[0]] > d + edge[1])
                {
                    dis[edge[0]] = d +edge[1];
                    pq.push({dis[edge[0]],edge[0]});
                }
            }
        }
        
        return dis;
        
      
    }
