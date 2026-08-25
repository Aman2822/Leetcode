class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();

        //Brute force- Hashmap

        // unordered_map<int,int> mp;

        // for(int i = 0 ; i < n ; i++){
        //     mp[nums[i]]++;
        // }

        // for(auto it : mp){
        //     if(it.second == 1) return it.first;
        // }
        // return 0;

        //Approach 2 - Like linear search - O(N)
        if(n == 1) return nums[0];
        if(nums[0] != nums[1]) return nums[0];
        if(nums[n-1] != nums[n-2]) return nums[n-1];

        for(int i = 1 ; i < n-1 ; i++){
            if(nums[i] != nums[i+1] && nums[i] != nums[i-1]){ // mid ele is not same as both left & right
                return nums[i];
            }
        }
        
        return -1;
    }
};