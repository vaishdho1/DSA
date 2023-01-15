/*
Approach:DSU 
There is a tree (i.e. a connected, undirected graph with no cycles) consisting of n nodes numbered from 0 to n - 1 and exactly n - 1 edges.

You are given a 0-indexed integer array vals of length n where vals[i] denotes the value of the ith node. You are also given a 2D integer array edges where edges[i] = [ai, bi] denotes that there exists an undirected edge connecting nodes ai and bi.

A good path is a simple path that satisfies the following conditions:

The starting node and the ending node have the same value.
All nodes between the starting node and the ending node have values less than or equal to the starting node (i.e. the starting node's value should be the maximum value along the path).
Return the number of distinct good paths.

Note that a path and its reverse are counted as the same path. For example, 0 -> 1 is considered to be the same as 1 -> 0. A single node is also considered as a valid path.

Store all the nodes sorted by values.
Start merging edges for a given value.
After merginf increment the count of the parent of each value
and add that to the result.

TC:O(n)
*/

class DSU{
    public:
    vector<int> rank;
    vector<int> parent;
    DSU(int n)
    {
        for(int i=0;i<n;i++)
        {
            rank.push_back(0);
            parent.push_back(i);
        }
    }
    
    int find(int x)
    {
        if(x!=parent[x])
            parent[x] = find(parent[x]);
        return parent[x];
    }
    
    void merge(int x,int y)
    {
       int par1 = find(x);
       int par2 = find(y);
       if(par1!=par2)
       {
           if(rank[par1]<rank[par2])
               parent[par1] = par2;
           else
           {
               parent[par2]=par1;
               if(rank[par1]==rank[par2])
                   rank[par1]++;
           }
       }
    }
};

class Solution {
public:
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int> >tree(n);
        map<int,vector<int> >node_val;
        
        DSU D(n);
        long long max_count = 0;
       
        for(auto edge:edges)
        {
            tree[edge[0]].push_back(edge[1]);
            tree[edge[1]].push_back(edge[0]);
            
        }
        for(int i=0;i<n;i++)
            node_val[vals[i]].push_back(i);

        for(auto it:node_val)
        {
            for(auto node:it.second)
            {
                for(auto edge:tree[node])
                {
                    if(vals[edge] <= vals[node])
                        D.merge(node,edge);
                }
            }
            unordered_map<int,int>count;
            for(auto node:it.second)
            {
                int par = D.find(node);
                count[par]++;
                max_count += count[par];
            }

        } 
       
    return max_count;        
    }
};
