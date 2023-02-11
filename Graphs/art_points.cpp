/*
Class which finds the articulation points in a graph
*/


#include <vector>
#include<iostream>
using namespace std;

class artPoints
{
    vector<int>res,low,disc,vis;
    public:
    artPoints(int n)
    {
        res.resize(n);
        low.resize(n);
        disc.resize(n);
        vis.resize(n);
    }

    void find_art(int src,int par,int timer,vector<vector<int> >&graph)
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
        if(vis[it])
            low[src] = min(low[src],disc[it]);
        else
        {
            cnt++;
            find_art(it,src,timer,graph);
            low[src] = min(low[src],low[it]);
            if(par == -1)
            {
                if(cnt >1)
                    res[src] = true;
            }
            else
            {
                if(low[it] >= disc[src])
                    res[src] = true;
            }
        }
        
    }

    }
    int calcPoints(int n)
    {
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            if(res[i])
                cnt++;
        }
        return cnt;
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
    art.find_art(0,-1,timer,graph);
    cout<<art.calcPoints(n);

}
