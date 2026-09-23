class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();

        //Approach 1 - Hashmap
        unordered_map<int, int> mp;
        vector<int> ans;

        for(int &num : nums){
            mp[num]++;
        }

        for(auto it : mp){
            if(it.second == 1){
                ans.push_back(it.first);
            }
        }

        return ans;


    }
};