int findWays(vector<int> &num, int tar)
{
    
    int n = num.size();
    vector<int>prev(tar+1,0);
    
    
    if(num[0]<=tar)
        prev[num[0]] = 1;
    if(num[0]==0)
        prev[0] = 2;
    else
        prev[0] = 1;
    
    for(int i=1;i<n;i++)
    {
        vector<int>cur(tar+1,0);
        for(int k=0;k<=tar;k++)
        {
            if(num[i]<=k)
            { 
               cur[k]+=prev[k-num[i]];
            }
            cur[k] += prev[k];
            
        }

        prev = cur;
    }
    return prev[tar];
   
}
