/*
Given an array of numbers, find the maximum xor between any 2 numbers.


Approach:
Use tries to keep storing the numbers from the left.
For a given number check for the number which is already in the trie and giving the max xor.
This can be checked by taking the current bit and checking if the inverted bit from the current
position is present.
Finally update the max_val variable after every iteration.

TC:O(32*n)
SC:O(2^32)
*/

struct Trie
{
    Trie * arr[2] = {};
    int value;
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
                }
                temp->value = num;
            }
        int max_xor(int num)
            {
                Trie * temp = root;
                for(int bit=31;bit>=0;bit--)
                {
                    int bitval = (num>>bit) &1;
                    if(temp->arr[!bitval])
                        temp = temp->arr[!bitval];
                    else if(temp->arr[bitval])
                        temp = temp->arr[bitval];
                    else
                        return -1e9;
                }
                return num ^ temp->value;
            }
    int findMaximumXOR(vector<int>& nums) {

        int max_val = 0;
        for(int i=0;i<nums.size();i++)
        {
            insert(nums[i]);
            max_val = max(max_val,max_xor(nums[i]));
        }
        return max_val;
        
    }
};
