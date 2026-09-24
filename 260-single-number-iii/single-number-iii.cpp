class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        if(n == 2) return nums;

        //Approach 1 - Hashmap
        // unordered_map<int, int> mp;
        vector<int> ans;

        // for(int &num : nums){
        //     mp[num]++;
        // }

        // for(auto it : mp){
        //     if(it.second == 1){
        //         ans.push_back(it.first);
        //     }
        // }

        // return ans;


        //Approach 2 - Bit Manipulation
        sort(begin(nums) , end(nums));

        for(int i = 0 ; i < n - 1 ; i++){
           int val = nums[i] ^ nums[i+1];
           if(val == 0){
            i++;
           }
           else{
            ans.push_back(nums[i]);
           }
        }

        if(ans.size() == 1){
            ans.push_back(nums[n-1]);
        }

        return ans;


        

    }
};