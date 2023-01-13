/*
Dp with number trick.Find number by using 10s 100s method till we reach >k and then break out
A program was supposed to print an array of integers. 
The program forgot to print whitespaces and the array is printed as a string of digits s and all we know 
is that all integers in the array were in the range [1, k] and there are no leading zeros in the array.
Given the string s and the integer k, return the number of the possible arrays that can be printed as s 
using the mentioned program. Since the answer may be very large, return it modulo 109 + 7.

TC:Nlog10(k)
*/

class Solution {
public:
    int mod = 1e9+7;
    int f(int ind,string&s,int n,int k,vector<int>&dp)
    {
        if(ind == n)
            return 1;

        if(s[ind] == '0')
            return 0;
        if(dp[ind] != -1)
            return dp[ind];
        int ways = 0; 
        long long num = 0;
        for(int i=ind;i<n;i++)
        { 
            num = num*10 + s[i]-'0';
            if(num >k)
                break;
            ways += f(i+1,s,n,k,dp);
            ways %= mod;
        }

        return dp[ind] = ways;
    }
    int numberOfArrays(string s, int k) {

        int n = s.size();
        vector<int>dp(n+1,0);
        //return f(0,s,n,k,dp);
        dp[n] = 1;
        for(int i=n-1;i>=0;i--)
        {
            if(s[i] == '0')
                continue;
            long long num = 0;

            for(int j=i;j<n;j++)
            {
                num = num*10 + s[j]-'0';
                if(num>k)
                    break;
                dp[i] = (dp[i] + dp[j+1])%mod;
            }
        }

        return dp[0];
    }
};
