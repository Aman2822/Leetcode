class Solution {
public:
    int singleNumber(vector<int>& nums) {

        // Approach 1 - Hashing - TC = O(N) AND SC = O(N)
        // unordered_map<int , int> mp;

        // for(int &num : nums){
        //    mp[num]++;
        // }

        // for(auto it : mp){
        //     if(it.second == 1) return it.first;
        // }

        // return -1;

        //Approach 2 - Bit Manipulation
        int n = nums.size();
        int ans  = 0; 

        //Count every place one's if its divisible by 3 if yes then add to the ans 

        for(int bitIdx = 0 ; bitIdx < 32 ; bitIdx++){
           int cnt = 0;
           for(int i = 0 ; i < n ; i++){
            if(nums[i] & (1 << bitIdx)){
                cnt++;
            }
           }

           if(cnt % 3 == 1){
            ans = ans | (1 << bitIdx);
           }
        }

        return ans;
        


    }
};