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

        //Approach 2 - Bit Manipulation - TC = O(N * 32) and SC - O(1)
        int n = nums.size();
        // int ans  = 0; 

        // //Count every place one's if its divisible by 3 if yes then add to the ans 

        // for(int bitIdx = 0 ; bitIdx < 32 ; bitIdx++){
        //    int cnt = 0;
        //    for(int i = 0 ; i < n ; i++){
        //     if(nums[i] & (1 << bitIdx)){
        //         cnt++;
        //     }
        //    }

        //    if(cnt % 3 == 1){
        //     ans = ans | (1 << bitIdx);
        //    }
        // }

        // return ans;

        
        //Approach 3 -  Sorting and checking every middle ele - TC = O(N * log N) + n/3  SC = O(1)
        // sort(begin(nums) , end(nums));

        // for(int i = 1 ; i < n ; i = i + 3){
        //     if(nums[i-1] != nums[i]){
        //         return nums[i-1];
        //     }
        // }

        // return nums[n-1];


        // Approach 4 - will the help of buckets(not intuitive approach ) - TC = O(N) and SC = O(1)
        int ones = 0 , twos = 0;

        for(int i = 0 ; i < n ; i++){
           
           //add the number it is not in twos
           ones = ones ^ nums[i] & ~twos;
           //Add the number if it is not in ones
           twos = twos ^ nums[i] & ~ones;
        }

        return ones;
        


    }
};