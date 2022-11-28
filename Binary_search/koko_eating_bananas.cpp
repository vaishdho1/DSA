/*
Variant of binary search on answers
*/

class Solution {
public:
    bool Koalacanfinish(vector<int>&pile, int mid,int h,int n)
    {
        long long time = 0;
        for(int i=0;i<n;i++)
        {   
            time += pile[i]/mid;
            if(pile[i]%mid != 0)
                time++;
        }
        
        return (time<=h);
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int n = piles.size();
        int low = 1;
        int high = *max_element(piles.begin(),piles.end());
        int ans = -1;

        while(low <= high)
        {
            int mid = (low + high)>>1;

            if(Koalacanfinish(piles,mid,h,n))
            {
                ans = mid;
                high = mid-1;
            }
            else
                low = mid + 1;
        }

        return ans;
        
    }
};
