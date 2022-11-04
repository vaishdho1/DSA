/*LIS variation.
Maximum height by stacking boxes such that the box below has the common area dimensions
greater than the box above,and the boxes can be placed along any face and there
are infinite number of each boxes available.

Approach:

1) Generate all variations of a box with different areas
2) Sort in the increasing order of area.
3) Apply LIS form for maximising height.
   i.e if the current box has length and width less than the box below it,
   and if the height increases after adding this block, update the height.

Complexity:
TC: O(n^2)
SC: O(n)
*/

#include <iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct box
{
    int width;
    int length;
    int height;
};
bool comp(box &b1,box &b2)
{
  return b1.length*b1.width > b2.length*b2.width;
}

void max_sum_incr(vector<box> arr)
{
    int n = arr.size();
    int maxi = 0;
    sort(arr.begin(),arr.end(),comp);
    vector<int>dp(n);
    for(int i=0;i<n;i++)
        dp[i] = arr[i].height;
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<i;j++)
        {
            if(arr[i].length < arr[j].length && arr[i].width < arr[j].width && dp[j] + arr[i].height > dp[i])
                dp[i] = dp[j] + arr[i].height;
        }
        if(dp[i] > maxi)
            maxi = dp[i];
    }
    cout<<maxi<<endl;
}
int main() {
    
    int n;
    cin>>n;
    vector<box>arr;
    box b;
    for(int i=0;i<n;i++)
    {
       
        int l,w,h;
        cin>>l>>w>>h;
        //First type
        b.length = min(l,w);
        b.width = max(l,w);
        b.height = h;
        arr.push_back(b);
        
        //Second type
        b.length = min(l,h);
        b.width = max(l,h);
        b.height = w;
        arr.push_back(b);
        
        //Third type
        
        b.length = min(w,h);
        b.width = max(w,h);
        b.height = l;
        arr.push_back(b);
    }
    max_sum_incr(arr);
}
        
