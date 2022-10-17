int minInsertions(string s) {
        int n = s.size();
        vector<int>dp(n+1,0);
        string t = "";

        for(int i=n-1;i>=0;i--)
            t+=s[i];
        
        for(int i=1;i<=n;i++)
        {
            vector<int>cur(n+1,0);
            for(int j=1;j<=n;j++)
            {
                if(s[i-1]==t[j-1])
                    cur[j] = 1+dp[j-1];
                else
                    cur[j] = max(dp[j],cur[j-1]);
            }
            dp = cur;
        }

        return n-dp[n];        

        
    }
