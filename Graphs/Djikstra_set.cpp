/*Implementation of Djikstra's using a set data structure
1) In the priority queue impelmentation we need to run !pq.empty() loop a few times
as we cant update in a priority queue but only insert.
2) In a set we update so the loop is run exactly V times.
3) But there is an extra cost of erase which can add a log(V^2) factor.
4) The time gain is not very sigificant and it depends on the way the graph and its edge weights.

TC: V(log(heap) + edges*(log(heap)))
edges can be V-1 in the worst case.
heap size can be V^2 in the worst case with every vertex put into the queue.
TC:V(V*log(V^2))
V^2 *log(V) (V-1 edges for each vertex * V)
~E *log(V)
*/

    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        set<pair<int,int>>s;
        vector<int>dis(V,1e9);
        dis[S] = 0;
        s.insert({0,S});
        
        while(s.size()!=0)
        {
            pair<int,int>X = *(s.begin());
            int node = X.second;
            int d = X.first;
            s.erase(s.begin());
            for(auto edge:adj[node])
            {
                if(dis[edge[0]] > d + edge[1])
                {
                    s.erase({dis[edge[0]],edge[0]});
                    dis[edge[0]] = d +edge[1];
                    s.insert({dis[edge[0]],edge[0]});
                }
            }
        }
        
        return dis;
        
      
    }
};
