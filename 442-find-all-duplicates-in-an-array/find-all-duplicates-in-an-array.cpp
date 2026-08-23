class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> mp;

        for (int i = 0; i < n; i++) {
            mp[nums[i]]++;
        }

        vector<int> duplicates;

        for (auto it : mp) {
            if(it.second == 2){
                duplicates.push_back(it.first);
            }
        }

        return duplicates;
    }
};