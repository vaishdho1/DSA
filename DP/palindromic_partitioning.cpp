/*
Idea : Partition Dp

Given a string, find the minimum number of cuts needed to partition it such that each
partition is a palindrome.

Approach:(More like LIS)

1) For finding the min number of cuts needed for partitioning a string from 0 to i - dp[i].
2)At every range go through the possible indices where a cut gives the possibility of palindrome
on one of the sides
    eg: if "abbab" , for i = 4, run j from 0 to 4, such that when str[i] == str[j], we can find if [j+1][i-1] was a palindrome,
        if yes, a cut can be performed at j-1 and the total number of ways are 1+dp[j-1].
3)Choose the minumum of all the cuts and store it in dp[i].
4)Return dp[n-1]

Complexity:

TC: O(n^2)
SC: O(n^2)

Approach 2:(Partition dp)
1) The above approach can be concluded by using the brute force partitioning, which works 
with a complexity of O(n^3).
2) For a partition i,j we compute for all values between i and j cut at each point such that the sum of cuts in partition before
  the cut and the cut is minimum.
3) We return dp[0][n-1].
4) Here for each i,j we need to check first if [i...j] is a palindrome and there is no way for us to know it before hand.
5) Also, the traversing through the range multiplies the complexity by n.
6) If we use a different partiton of complexity O(N) and if we are able to calculate whether the substring is a
   palindrome or not on the go,we can add a cut at that point if it is a palindrome and use the already computed value from the
   other partition.
7) Here mainly we solve only one partiton as the other one is already a palindrome.
Approach 1 uses this idea.

Conclusion: Sometimes how we patition might make the problem easier to solve with a lower time complexity.

*/

int palindromicPartition(string str)
    {
        // code here
        int n = str.size();
        vector<int>dp(n);
        vector<vector<bool>>is_pal(n,vector<bool>(n,false));
        
        
        for(int i = 0;i<n;i++)
        {
            int min_cuts = i;
            for(int j = 0;j<=i;j++)
            {
                //cout<<i<<" "<<j<<" "<<is_pal[i-1][j+1]<<endl;
                if(str[i] == str[j] && (i-j<2 || is_pal[i-1][j+1]))
                {
                    is_pal[i][j] = true;
                    if(j==0)
                        min_cuts = 0;
                    else
                        min_cuts = min(min_cuts,1+dp[j-1]);
                }
                
            }
            dp[i] = min_cuts;
        }
        
       
        
        return dp[n-1];
    }
