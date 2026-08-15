class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        bool allZero = true;
        int resultXor = 0;

        for (int& i : nums) {
            resultXor = (resultXor ^ i);

            if(i != 0){  // Check at least one is non zero
                allZero = false;
            }
        }

        if(allZero){   // If all are zero then there is no subsequence which is non zero
            return 0;
        }

        return (resultXor == 0) ? n - 1 : n ; // If full array is xor is 0 then there is one element that is disturbing so remove it and return n - 1  and if full xor is non zero then return n 
    }
};