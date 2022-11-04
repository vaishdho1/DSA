/*
LCS variant

Length of the longest palindromic subsequence.

Approach:
Reverse the array and find the length of the longest common
subsequence.

TC: O(n^2)
SC: O(n)
*/

string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));

        int max_len = 0;
        int x_co = 0;
        int y_co = 0;
        for(int i=0;i<n;i++)
            dp[i][i] = 1;

        for(int i=n-1;i>=0;i--)
        {
            
            for(int j =i+1 ;j<n;j++)
            {
                if(s[i] == s[j])
                {
                    if(j-i==1 || dp[i+1][j-1]==true)
                    {
                        dp[i][j] = true;
                        if(j-i+1>max_len)
                        {
                            max_len = j-i+1;
                            x_co = i;
                            y_co = j;
                        }
                    }
                    
                }
                    
            }
        }
         
    

    return s.substr(x_co,y_co-x_co+1);

    }
