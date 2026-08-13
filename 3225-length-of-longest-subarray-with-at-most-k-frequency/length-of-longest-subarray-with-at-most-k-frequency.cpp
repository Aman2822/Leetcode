class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();

        //Sliding Window Problem 
        // unordered_map<int , int> mp;

        // int i = 0 , j = 0;
        // int result = 0;

        // while(j < n){

        //     mp[nums[j]]++;

        //     while(i < j && mp[nums[j]] > k){
        //         mp[nums[i]]--;
        //         i++;
        //     }

        //     result =  max(result , j-i+1);
        //     j++;
        // }
        // return result;

        // Approach 2 

        unordered_map<int, int> mp;

        int i = 0 , j = 0;
        int result = 0;
        int culprit = 0;

        while(j < n){
            mp[nums[j]]++;

            // When mp[nums[j]] is greater than k then culprit is incremented
            if(mp[nums[j]] == k+1){
                culprit++;
            }

            if(culprit > 0){
                //If culprit is greater than 0 then we reduce the mp[nums[i]] because we  have to shrink the window
                mp[nums[i]]--;
                // After shrinking if the frequency is  reduced from k + 1 to k then that integer was culprit so we  decrement the culprit and after 
                if(mp[nums[i]] == k){
                    culprit--;
                }
                // Shrinked the window
                i++;
            }
            
            // Culprit is 0 then it is considered as a good so we have to include it in the result
            if(culprit == 0){
                result = max(result , j - i + 1);
            }
            j++;
        }
        return result;


    }
};