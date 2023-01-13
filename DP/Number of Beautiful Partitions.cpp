/*
2478
You are given a string s that consists of the digits '1' to '9' and two integers k and minLength.

A partition of s is called beautiful if:

s is partitioned into k non-intersecting substrings.
Each substring has a length of at least minLength.
Each substring starts with a prime digit and ends with a non-prime digit. Prime digits are '2', '3', '5', and '7', and the rest of the digits are non-prime.
Return the number of beautiful partitions of s. Since the answer may be very large, return it modulo 109 + 7.

A substring is a contiguous sequence of characters within a string.

Approach:
Normal dp with optimization using prefix sum.
TC:O(n*k)
*/

class Solution {
public:
    int mod = 1e9+7;
    bool isPrime(char ch)
    {
        return (ch == '2' || ch =='3' || ch=='5' || ch =='7');
    }
   int f(int ind,int k,int n,int minlen,string s,vector<vector<int>>&dp)
   {
       if(k==1)
       {
           if(isPrime(s[ind]) && !isPrime(s[n-1]) && n-ind >=minlen)
                return 1;
            return 0;
       }

       if(ind == n-1)
            return 0;
        
       if(!isPrime(s[ind]))
            return 0;
        if(dp[ind][k] != -1)
            return dp[ind][k];
        int ways = 0;
       for(int i=ind+minlen-1;i<n-1;i++)
       {
           if(isPrime(s[i]))
                continue;
           ways = (ways +f(i+1,k-1,n,minlen,s,dp))%mod;
       }
        //cout<<ind<<" "<<k<<" "<<ways<<endl;
       return dp[ind][k] = ways;
   }
       
    int beautifulPartitions(string s, int k, int minLength) {
        int n = s.size();
        vector<vector<int>>dp(n,vector<int>(k+1,0));
        vector<vector<int>>prefSum(n+minLength,vector<int>(k+1,0));
        //return f(0,k,n,minLength,s,dp);

        
        for(int i=n-2;i>=0;i--)
        {
            
            for(int j=1;j<=k;j++)
            {
                 
                if(!isPrime(s[i]))
                    dp[i][j] = 0;
                
                else if(j == 1)
                {
                    if(isPrime(s[i]) && !isPrime(s[n-1]) && n-i >=minLength)
                        dp[i][1] = 1;
                }
                else
                 dp[i][j] = (dp[i][j] + prefSum[i+minLength-1][j-1])%mod;

                 if(!isPrime(s[i]))
                    prefSum[i][j] = (dp[i+1][j] + prefSum[i+1][j])%mod;
                 else
                    prefSum[i][j] = prefSum[i+1][j];
            }
        }
       

       
       

        return dp[0][k];


    }

        
};
