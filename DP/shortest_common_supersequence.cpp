string shortestCommonSupersequence(string str1, string str2) {

        int n = str1.size();
        int m = str2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int i =1;i<=n;i++)
        {
            for (int j = 1; j<= m; j++)
            {
                if(str1[i-1] == str2[j-1])
                    dp[i][j] = 1 + dp[i-1][j-1];
                else
                    dp[i][j] = max(dp[i-1][j] , dp[i][j-1]);
            }
        }

        int i = n;
        int j = m;
        string out = "";

        while(i>0 || j>0)
        {
            if(i==0)
            {
                out+=str2[j-1];
                j--;
            }
            else if(j==0)
            {
                out+=str1[i-1];
                i--;
            }
            else
            {
                if(str1[i-1] == str2[j-1])
                {
                    out+=str1[i-1];
                    i--;
                    j--;
                }
                else if(dp[i][j] == dp[i-1][j])
                {
                    out+=str1[i-1];
                    i--;
                }
                else
                {
                    out+=str2[j-1];
                    j--;
                }
            }
        }
         
        reverse(out.begin(),out.end());
        return out;
        
    }
