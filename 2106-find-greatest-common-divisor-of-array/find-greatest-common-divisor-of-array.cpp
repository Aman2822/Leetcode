class Solution {
public:
    int findGCD(vector<int>& nums) {
        // int max_ele = *max_element(nums.begin() , nums.end());
        // int min_ele = *min_element(nums.begin() , nums.end());
        
        int n = nums.size();
        int max_ele = INT_MIN, min_ele = INT_MAX;

        for(int i = 0 ; i < n; i++){
            max_ele = max(max_ele , nums[i]);
        }
        
        for(int i = 0 ; i < n ;i++){
            min_ele = min(min_ele , nums[i]);
        }

        int gcd = __gcd(max_ele,min_ele);
        return gcd;
    }
};