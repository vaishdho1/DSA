/*
Precomputation based dp.

 We cut through all possible rows and columns and find the total number
 of ways.
 TC:(n*m)*k*(n+m)*(n+m)
 
 To reduce the time complexity, we can replace the isValid function, which takes (m*n) per call.
 We precompute the total number of apples in prefsum[row][col] - Total number of apples
 present from row to n and col to m.
 TC:(n*m)*k(n+m)
*/


class Solution {
public:
    int mod = 1e9+7;
    bool isValid(int stRow,int endRow,int stCol,int endCol,vector<string>&pizza)
    {
        for(int i=stRow;i<endRow;i++)
        {
            for(int j=stCol;j<endCol;j++)
            {
                if(pizza[i][j] == 'A')
                    return true;
            }
        }
        return false;
    }
    int f(int row,int col,int n,int m,vector<string>& pizza, int k,vector<vector<vector<int>>>&dp)
    {
        if(k==1)
        {
            
            if(isValid(row,n,col,m,pizza))
                return 1;
            return 0;
        }
        if(dp[row][col][k] != -1)
            return dp[row][col][k];
        int duprow = row;
        int dupcol = col;
        int ways = 0;

        while(row < n-1)
        {
            if(isValid(duprow,row+1,col,m,pizza))
                ways = (ways+f(row+1,col,n,m,pizza,k-1,dp))%mod;
            row++;
        }
        row= duprow;

        while(col < m-1)
        {
            if(isValid(row,n,dupcol,col+1,pizza))
                ways = (ways+f(row,col+1,n,m,pizza,k-1,dp))%mod;
            col++;
        }
        row = duprow;
        col = dupcol;
        return dp[row][col][k] = ways;
    }
    int ways(vector<string>& pizza, int k) {
        int n = pizza.size();
        int m = pizza[0].size();
        vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(m+1,vector<int>(k+1,0)));
        vector<vector<int>>prefSum(n+1,vector<int>(m+1,0));
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(pizza[i][j]=='A')
                    prefSum[i][j] = 1;    
                prefSum[i][j] += prefSum[i+1][j] + prefSum[i][j+1] - prefSum[i+1][j+1] ;
            }
        }
        for(int row=0;row<=n;row++)
        {
            for(int col=0;col<=m;col++)
            {
                if(prefSum[row][col])
                    dp[row][col][1] = 1;
            } 
        }

        for(int row = n-1;row>=0;row--)
        {
            for(int col = m-1;col>=0;col--)
            {
                for(int l = 2;l<=k;l++)
                {
                    int ways = 0;
                    for(int i=row;i<n-1;i++)
                    {
                        if(prefSum[row][col] - prefSum[i+1][col] > 0)
                            ways = (ways+dp[i+1][col][l-1])%mod;
                    }
                    for(int i=col;i<m-1;i++)
                    {
                        if(prefSum[row][col] - prefSum[row][i+1] > 0)
                            ways = (ways+dp[row][i+1][l-1])%mod;
                    }
                    dp[row][col][l] = ways;
                }
            }
        }
        

        return dp[0][0][k];


    }
};
