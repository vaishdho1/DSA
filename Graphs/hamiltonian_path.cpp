

bool f(int node,int state,int endState,vector<vector<int>>&graph,vector<vector<int>>&dp)
    {
        if(state == endState)
            return true;
        if(dp[node][state] != -1)
            return dp[node][state];
        
        bool res = false;
        for(auto it:graph[node])
        {
            if(((state>>it)&1) == 0)
                res |= f(it,state|(1<<it),endState,graph,dp);
        }
        return dp[node][state] = res;
}
    bool isHamilPresent(int N,int M,vector<vector<int>> Edges)
    {
        // code here
        vector<vector<int>>graph(N);
        int endState = (1<<N)-1;
        vector<vector<int>>dp(N,vector<int>(endState+1,-1));
        
        for(auto it:Edges)
        {
            graph[it[0]-1].push_back(it[1]-1);
            graph[it[1]-1].push_back(it[0]-1);
        }
        for(int i=0;i<N;i++)
        {
            if(f(i,(1<<i),endState,graph,dp))
                return true;
            
        }
        return false;
        
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	}
}
// } Driver Code Ends
