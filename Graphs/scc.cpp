/*
Finds the number of strongly connected components using kosaraju's algorithm.
The idea is to strore the nodes as they are visisted post orderly into a stack.
This works for the following reasons:
a)  The idea is if there is an edge from one component to the other and the first component is
visited first,the nodes of the current component are placed at the top of the stack and can be used
on the reverse graph to find all nodes within the component.i.e tout[v]>tout[x]
b) If the other component is visited before the first one,we are definitely sure that the first component nodes
are at the top of the stack and running dfs on the elements at the top would suffice.
  */

void dfs(int node,vector<vector<int>>& graph,vector<int>&vis,stack<int>&st)
	{
	    vis[node]=1;
	    for(auto it:graph[node])
	    {
	        if(!vis[it])
	            dfs(it,graph,vis,st);
	    }
	    st.push(node);
	}
    int kosaraju(int V, vector<vector<int>>& adj)
    {
        //code her
        stack<int>st;
        vector<int>vis(V,0);
        vector<int>vis1(V,0);
        stack<int>st1;
        int count = 0;
        vector<vector<int>>revGraph(V);
        vector<vector<int>>graph(V);
        for(int i=0;i<V;i++)
        {
            for(auto it:adj[i])
                revGraph[it].push_back(i);
        }
        for(int i=0;i<V;i++)
        {
            if(vis[i]==0)
                dfs(i,adj,vis,st);
        }
        while(!st.empty())
        {
            int node = st.top();
            st.pop();
            if(vis1[node]==0)
            {
                dfs(node,revGraph,vis1,st1);
                count++;
            }
        }
        return count;   
    }
