class Solution {
public:
    /*
    sliding window pehle elements nikal lo distinct full array and then it becomes a problem of subarray of k distinct numbers
    */

    int sliding(vector<int>& nums , int k){
        int n = nums.size();
        
        unordered_map<int , int> mp;
        if(k == 0) return 0;
        int i = 0 , j = 0 , res = 0;

        while(j < n){
            mp[nums[j]]++;

            while(i < j && mp.size() > k){
                mp[nums[i]]--;
                if(mp[nums[i]] == 0){
                    mp.erase(nums[i]);
                }
                i++;
            }

            res += (j - i + 1);

            j++;
        }

        return res;
    }

    int countCompleteSubarrays(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int > mp;


        for(int &num : nums){
            mp[num]++;
        }

        int k = mp.size();
        
        return sliding(nums , k) - sliding(nums , k - 1);
        
    }
};