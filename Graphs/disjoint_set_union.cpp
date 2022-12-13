#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Disjoint_set
{
    vector<int>rank,parent;
    public:
    Disjoint_set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        for(int i=0;i<=n;i++)
            parent[i] = i;
    }

    //Path compression ~O(1)
    int findpar(int node)
    {
        if(node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }

    void unionByRank(int u,int v)
    {
        int par_u = findpar(u);
        int par_v = findpar(v);

        if(par_u==par_v)
            return;
        if(rank[par_u] > rank[par_v])
        {
            parent[par_v] = par_u;
        }
        else
        {
            if(rank[par_u] == rank[par_v])
                rank[par_v]++;
            parent[par_u] = par_v;
        }
    }
};

int main()
{
    Disjoint_set ds(7);
    ds.unionByRank(1,2);
    ds.unionByRank(2,3);
    ds.unionByRank(4,5);
    ds.unionByRank(6,7);
    ds.unionByRank(5,6);
    if(ds.findpar(3) == ds.findpar(7))
     cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;
      ds.unionByRank(3,7);
       if(ds.findpar(3) == ds.findpar(7))
     cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;

}
