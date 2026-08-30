class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int , int> mp;
        int special = 0;

        for(int i = 0 ; i < n ; i++){
            mp[nums[i]]++;
        }

        for(auto it : mp){
            int ele = it.first;
            int freq = it.second;

            int first = -1 , last = -1;
            for(int i = 0 ; i < n ; i++){
                if(nums[i] == ele){
                    if(first == -1) first = i;
                    last = i;
                } 
            }
            int range = last - first + 1;
            if(range == freq){
                special++;
            }
        }
        return special;
    }
};