/*
Implemented disjoint set data structure both union by rank and union by size
part.
TC:O(4alpha) ~O(1)
*/


#include <iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

class Disjoint_set
{
    vector<int>rank,parent,size;
    public:
    Disjoint_set(int n)
    {
        rank.resize(n+1,0);
        parent.resize(n+1);
        size.resize(n+1,1);
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

    void unionBysize(int u,int v)
    {
        int par_u = findpar(u);
        int par_v = findpar(v);

        if(par_u==par_v)
            return;
        if(size[par_u] > size[par_v])
        {
            parent[par_v] = par_u;
            size[par_u] += size[par_v];
        }
        else
        {
            parent[par_u] = par_v;
            size[par_v] += size[par_u];
        }
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
    ds.unionBysize(1,2);
    ds.unionBysize(2,3);
    ds.unionBysize(4,5);
    ds.unionBysize(6,7);
    ds.unionBysize(5,6);
    if(ds.findpar(3) == ds.findpar(7))
     cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;
      ds.unionBysize(3,7);
       if(ds.findpar(3) == ds.findpar(7))
     cout<<"same"<<endl;
    else
        cout<<"not same"<<endl;

}
