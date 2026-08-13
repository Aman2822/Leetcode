class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int n = nums.size();
        int max_prod;

        sort(nums.begin() , nums.end());

        max_prod = (nums[n-1] * nums[n-2]) - (nums[0] * nums[1]);

        return max_prod;
    }
};