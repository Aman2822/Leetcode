class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> disappear;

        vector<int> missing;

        // Insert all element into the set
        for (int i = 0; i < n; i++) {
            disappear.insert(nums[i]);
        }

        for (int i = 1; i <= n; i++) {
            if(!disappear.contains(i)){
                missing.push_back(i);
            }
        }

        return missing;
    }
};