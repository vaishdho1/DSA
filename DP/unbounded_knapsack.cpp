int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    vector<int>dp(w+1,0);
    for(int k=1;k<=w;k++)
        dp[k] = ((int)k/weight[0])*profit[0];
    
    for(int i=1;i<n;i++)
    {
        for(int j=0;j<=w;j++)
        {
            int not_take = dp[j];
            int take = -1;
            if(weight[i]<=j)
                take = profit[i]+dp[j-weight[i]];
            dp[j] = max(take,not_take);
        }

    }
    return dp[w];
    
}
