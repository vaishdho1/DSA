/*
You wrote down many positive integers in a string called num. 
However, you realized that you forgot to add commas to seperate the different numbers.
You remember that the list of integers was non-decreasing and that no integer had leading zeros.
Return the number of possible lists of integers that you could have written down to get the string num.
Since the answer may be large, return it modulo 109 + 7.
*/

class Solution {
public:
    int mod = 1e9+7;
    int f(int end,int len,string num,vector<vector<int>>&dp)
    {
        //cout<<end<<" "<<len<<endl;
        if(num[end-len+1] == '0')
            return 0;
        if(end-len+1 == 0)
            return 1;
        if(dp[end][len] != -1)
            return dp[end][len];
        int ways = 0;
        int out;
        if(end-len+1 < len)
            out = end-len+1;
        else if(end-len-len+1 >=0 && num.substr(end-len-len+1,len) <= num.substr(end-len+1,len))
            out = len;
        else
            out = len-1;
        //cout<<"out "<<out<<endl;
        for(int i=1;i<=out;i++)
        {
            //cout<<i<<endl;
            ways = (ways +f(end-len,i,num,dp))%mod;
        }
        
         //cout<<end<<" "<<len<<endl;
        return dp[end][len] = ways;
        
    }
    int numberOfCombinations(string num) {
        int n = num.size();
        vector<vector<int>>dp(n,vector<int>(n+1,0));
        //prefSum[i][j] - Total number of splits such that the last number ends at i and the length is from 1 to j
        vector<vector<int>>prefSum(n,vector<int>(n+1,0));
        vector<vector<int>>same(n+1,vector<int>(n+1,0));

        for(int i=n-2;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(num[i] == num[j])
                    same[i][j] = 1 + same[i+1][j+1];
            }
        }


        int ways = 0;

        for(int end = 0;end <n;end++)
        {
            for(int len=1;len<=end+1;len++)
            {
                int cur = 0;
                int start = end-len+1;
                if(num[start] == '0')
                    cur = 0;
                else if(start == 0)
                    cur = 1;
                else
                {
                    int out;
                    if(start < len)
                        out = start;
                    else 
                    {
                    int x = same[start-len][start];
                    if(x >= len || num[start -len+x] <= num[start+x])
                        out = len;
                    else
                        out = len-1;
                    }
                    cur = (cur +prefSum[start-1][out])%mod;
                }
                 prefSum[end][len] = (prefSum[end][len-1] + cur)%mod;    
            }
        }

       return prefSum[n-1][n];

    }
};
