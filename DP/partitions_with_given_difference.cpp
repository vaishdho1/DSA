int countPartitions(int n, int d, vector<int> &arr) {
    int mod = 1e9+7;
    int sum = 0;
    for(int i=0;i<n;i++)
        sum+=arr[i];
    if(d>sum || (sum+d)%2==1)
        return 0;
    sum = (sum+d)/2;
    vector<int>dp(sum+1,0);
    
    if(arr[0]==0)
        dp[0] = 2;
    else
        dp[0] = 1;
    if(arr[0]!=0 &&arr[0]<=sum )
         dp[arr[0]]=1;
  
    for(int i=1;i<n;i++)
    {
         vector<int>cur(sum+1,0);
        for(int k=0;k<=sum;k++)
        {
            int not_take = dp[k];
            int take = 0;
            if(arr[i]<=k)
                take = dp[k-arr[i]];
            cur[k] = (take+not_take)%mod;
            
        }
        dp = cur;
    }
    return dp[sum];
    
}
