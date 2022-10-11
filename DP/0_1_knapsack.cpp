//Recursive code - top_down TC: O(n*w) SC:O(n*w)+O(n)(recursive stack space)

int rec_profit(int ind,int weight,vector<int> &values, vector<int> &arr,vector<vector<int> >&dp)
{
    
    if(weight==0)
        return 0;
    if(ind==0)
    {
        if(arr[ind]<=weight)
            return values[ind];
        else
            return 0;
    }
    if(dp[ind][weight])
        return dp[ind][weight];
    
    int take = -1;
    int not_take = rec_profit(ind-1,weight,values,arr,dp);
    if(arr[ind]<=weight)
        take = values[ind]+rec_profit(ind-1,weight-arr[ind],values,arr,dp);
    return dp[ind][weight] = max(take,not_take);
}

//DP - bottom_up TC: O(N*w)  SC:O(n*w)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
	// Write your code here
    vector<vector<int> >dp(n,vector<int>(w+1,-1));
    //return rec_profit(n-1,w,values,weights,dp);
    for(int k=0;k<=w;k++)
    {
        if(weights[0]<=k)
            dp[0][k] = values[0];
    }
    
    for(int i=1;i<n;i++)
    {
        for(int k=0;k<=w;k++)
        {
            int take = -1;
            int not_take = dp[i-1][k];
            if(weights[i]<=k)
                take  = values[i] + dp[i-1][k-weights[i]];
            dp[i][k] = max(take,not_take);
        }
    }
    return dp[n-1][w];
}

//DP - bottom_up TC: O(N*w) SC: O(w+1)

int maxProfit(vector<int> &values, vector<int> &weights, int n, int w)
{
    vector<int>dp(w+1,0);
   
    for(int k=0;k<=w;k++)
    {
        if(weights[0]<=k)
            dp[k] = values[0];
    }
    
    for(int i=1;i<n;i++)
    {
        vector<int>cur(w+1,0);
        for(int k=0;k<=w;k++)
        {
            int take = -1;
            int not_take = dp[k];
            if(weights[i]<=k)
                take = values[i] + dp[k-weights[i]];
            cur[k] = max(take,not_take);
        }
        dp = cur;
    }
    return dp[w];
}
