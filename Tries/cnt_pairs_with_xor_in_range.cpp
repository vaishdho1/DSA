/*
Given an array count pairs (i,j) such that the xor is in the range
low and high.

Approach:
1) We can use a Trie based appraoch for this.
2) The basic idea is to store the numbers in a trie and 
before storing to count the number of numbers with xor in range low and high.
3) The problem here is that, counting requires that we check for numbers which are less than say high.
4) For this we start from the MSB and see how many numbers are there in the tree starting with a value such that
the XOR of that number with the current number gives a 0.
eg: If we have num = 1001 and limit = 1100, we want 1 in the MSB so that we get numbers which start at 0 and 0 is less than 1.We can count such numbers
by using a variable count at each node in the trie.We then move to the branch 0 here as we should go towards 1001 and xor of 1 and 0 is 1.
5) We then move towards the branch which gives the same number as the limit, at every point in the traversal we check if
we have numbers beginning at this bit and starting with 0.If we do, we add them if the branch we are going is not same as this number.
6)Towards the end we add the count at the last digit of the limit.This will also count the limit.
7)We need to run for high and subtract low-1.

TC:O(32*n*2)
SC:O(2^32)

*/

struct Trie
    {
     Trie * arr[2] = {};
     int count = 0;
    };
class Solution {
public:
        Trie * root = new Trie; 
        void insert(int num)
            {
                Trie * temp = root;
                for(int bit = 31;bit>=0;bit--)
                {
                    int bitval = (num>>bit) &1;
                    if(!temp->arr[bitval])
                        temp->arr[bitval] = new Trie();
                    temp = temp->arr[bitval];
                    temp->count++; 
                }
            }
        int find_nice(int num,int limit)
        {
            int cnt = 0;
            Trie * temp = root;
            for(int bit=31;bit>=0;bit--)
            {
                int num_val = (num>>bit) & 1;
                int lim_val = (limit>>bit) & 1;
                int add = num_val;
                int move = lim_val^num_val;
                if(add!= move && temp->arr[add])
                    cnt += temp->arr[add]->count;
                
                if(temp->arr[move])
                    temp = temp->arr[move];
                else
                    return cnt;
            }
            cnt += temp->count;
            return cnt;
        }
    int countPairs(vector<int>& nums, int low, int high) {
        int n = nums.size();
        int cnt = 0;
        for(int i=0;i<n;i++)
        {
            cnt+= find_nice(nums[i],high)-find_nice(nums[i],low-1);
            insert(nums[i]);
        }
        return cnt;
    }
};
