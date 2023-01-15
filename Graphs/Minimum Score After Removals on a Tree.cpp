/*
There is an undirected connected tree with n nodes labeled from 0 to n - 1 and n - 1 edges.

You are given a 0-indexed integer array nums of length n where nums[i] represents the value of the ith node. You are also given a 2D integer array edges of length n - 1 where edges[i] = [ai, bi] indicates that there is an edge between nodes ai and bi in the tree.

Remove two distinct edges of the tree to form three connected components. For a pair of removed edges, the following steps are defined:

Get the XOR of all the values of the nodes for each of the three components respectively.
The difference between the largest XOR value and the smallest XOR value is the score of the pair.
Use dfs for calculationg XOR for each subtree starting from 0.
Pick an edge and find the first component.
And iterate through all the edges by cutting them and finding
the xor of other 2 components.
O(n^2)
*/
class Solution {
public:
    int min_val =1e9;
    int dfs(int root,int par,vector<int>& nums,vector<vector<int>>&graph,vector<int>&dp)
    {
        int res = nums[root];

        for(auto it:graph[root])
        {
            if(it == par)
                continue;
            res ^= dfs(it,root,nums,graph,dp);
        }
        return dp[root] = res;
    }

    int dfs2(int root,int par,vector<int>& nums,vector<vector<int>>&graph,int tot,int firstval)
    {
        int sum = nums[root];

        for(auto it:graph[root])
        {
            if(it == par)
                continue;
            int sub = dfs2(it,root,nums,graph,tot,firstval);
            sum ^= sub;
            int secondval = sub;
            int thirdval = tot ^sub;
            min_val = min(min_val,max(max(firstval,secondval),thirdval)-min(min(firstval,secondval),thirdval));
        }   

        return sum;
    }
    int minimumScore(vector<int>& nums, vector<vector<int>>& edges) {
        int n = nums.size();
        vector<int>dp(n,0);
        vector<vector<int>>graph(n);
        vector<int>vis(n,0);
        for(auto it:edges)
        {
            graph[it[0]].push_back(it[1]);
            graph[it[1]].push_back(it[0]);
        }
        int tot = dfs(0,-1,nums,graph,dp);
        queue<int>q;
        q.push(0);
        vis[0] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it:graph[node])
            {
                if(vis[it])
                    continue;
                vis[it] = 1;
                q.push(it);
                int rem = tot ^ dp[it];
                dfs2(node,it,nums,graph,rem,dp[it]);
            }
        }
        return min_val;

       
        
    }
};
