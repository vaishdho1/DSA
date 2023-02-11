/*
Find the bridges in a graph
*/


class Bridges
{
    vector<int>low,disc,vis;
    vector<vector<int> >res;
    public:
    Bridges(int n)
    {
        low.resize(n);
        disc.resize(n);
        vis.resize(n);
    }

    void find_bridges(int src,int par,int timer,vector<vector<int> >&graph)
    {   

        vis[src] = 1;
        disc[src] = timer;
        low[src] = timer;
        timer++;
        int cnt = 0;
        for(auto it:graph[src])
        {
            
            if(it == par)
                continue;
          //Node is already visited, update the low if the neighbour's low is smaller
            if(vis[it])
                low[src] = min(low[src],disc[it]);
            //continue with dfs and update the low if the neighbour's low is smaller
            else
            {

                find_art(it,src,timer,graph);
                low[src] = min(low[src],low[it]);
                if(low[it] > disc[src])
                        res.push_back({src,it});
            }
            
        }

    }
    vector<vector<int> >critical_connections()
    {
        return res;
    }

};

int main()
{
    int n;
    cin>>n;
    int m;
    cin>>m;
    vector<vector<int> >graph(n);
    for(int i=0;i<m;i++)
    {
        int x,y;
        cin>>x>>y;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }
    
    int timer = 0;
    artPoints art(n);
    art.find_bridges(0,-1,timer,graph);
    vector<pair<int,int> >res = art.critical_connections();
    for(auto it:res)
        cout<<it.first<<" "<<it.second<<endl;
    


}

