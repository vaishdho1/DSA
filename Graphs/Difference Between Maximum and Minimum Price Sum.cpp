/*
There exists an undirected and initially unrooted tree with n nodes indexed from 0 to n - 1. You are given the integer n and a 2D integer array edges of length n - 1, where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Each node has an associated price. You are given an integer array price, where price[i] is the price of the ith node.

The price sum of a given path is the sum of the prices of all nodes lying on that path.

The tree can be rooted at any node root of your choice. The incurred cost after choosing root is the difference between the maximum and minimum price sum amongst all paths starting at root.

Return the maximum possible cost amongst all possible root choices.

Approach 1:Using 2 dfs runs with rerooting conditions.

Approach2 :dp with memoization of dp[root][parent]

TC:O(n)

*/
//Approach 1
class Solution {
public:
    long long ans = 0;
    long long dfs1(int root,int par,vector<vector<int>>&tree,vector<pair<long long,long long>>&maxPath,unordered_map<int,pair<int,int>>&pathInd,vector<int>& price)
    {
        
        //cout<<root<<endl;
        long long maxsum1=0,maxsum2=0;
        int find=-1,secind=-1;
        for(auto it:tree[root])
        {
            if(it == par)
                continue;
            int sum = dfs1(it,root,tree,maxPath,pathInd,price);
            if(sum > maxsum2)
            {
                maxsum2=sum;
                secind = it;
                if(maxsum2 > maxsum1)
                {
                    swap(maxsum2,maxsum1);
                    swap(find,secind);
                }
            }
        }
        maxPath[root].first = maxsum1 + price[root];
        maxPath[root].second = maxsum2 + price[root];
        pathInd[root].first = find;
        pathInd[root].second = secind;
        return maxPath[root].first;
        
    }
    
    void dfs2(int root,int par,long long value,vector<vector<int>>&tree,vector<pair<long long,long long>>&maxPath,unordered_map<int,pair<int,int>>&pathInd,vector<int>& price)
    {
        long long sum = value +price[root];
            
        if(sum > maxPath[root].second)
            {
                maxPath[root].second=sum;
                pathInd[root].second= par;
                if(maxPath[root].second > maxPath[root].first)
                {
                    swap(maxPath[root].second,maxPath[root].first);
                    swap(pathInd[root].first,pathInd[root].second);
                }
            }
        
        
        ans = max(ans,maxPath[root].first-price[root]);
        
        for(auto it:tree[root])
        {
            if(it == par)
                continue;
            if(pathInd[root].first == it)
                dfs2(it,root,maxPath[root].second,tree,maxPath,pathInd,price);
            else
                dfs2(it,root,maxPath[root].first,tree,maxPath,pathInd,price);
        }
        
    }
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>>tree(n);
        vector<pair<long long,long long>>maxPath(n);
        unordered_map<int,pair<int,int>>pathInd;
        for(auto it:edges)
        {
            tree[it[0]].push_back(it[1]);
            tree[it[1]].push_back(it[0]);
        }
        dfs1(0,-1,tree,maxPath,pathInd,price);
        dfs2(0,-1,0,tree,maxPath,pathInd,price);
        return ans;
        
    }
};

class Solution {
public:
    long long ans = 0;
    
    long long dfs(int root,int par,vector<vector<int>>&tree,vector<int>& price, vector<vector<long long>>&dp)
    {
    
        if(dp[root][par]!=-1)
            return dp[root][par];
        long long sum = 0;
        for(auto it:tree[root])
        {
            if(it == par)
                continue;
            sum = max(sum,dfs(it,root,tree,price,dp));
        }
        
        return dp[root][par] = sum + price[root-1];
    }
    
    long long maxOutput(int n, vector<vector<int>>& edges, vector<int>& price) {
        vector<vector<int>>tree(n+1);
        vector<vector<long long>>dp(n+1,vector<long long>(n+1,-1));
        for(auto it:edges)
        {
            tree[it[0]+1].push_back(it[1]+1);
            tree[it[1]+1].push_back(it[0]+1);
        }
        
        for(int i=1;i<=n;i++)
        {
            long long res = dfs(i,0,tree,price,dp);
            ans = max(ans,res-(long long)price[i-1]);
        }
       
        return ans;
        
    }
};
