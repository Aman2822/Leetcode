class Solution {
public:
    int findGCD(vector<int>& nums) {
        int max_ele = *max_element(nums.begin() , nums.end());
        int min_ele = *min_element(nums.begin() , nums.end());

        int gcd = __gcd(max_ele,min_ele);
        return gcd;
    }
};