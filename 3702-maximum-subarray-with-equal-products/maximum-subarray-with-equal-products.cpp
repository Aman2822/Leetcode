class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n = nums.size();
        int res = 0;

        for(int i = 0 ; i < n ; i++){
            int prod = nums[i];
            int l = nums[i];
            int g = nums[i];

            for(int j = i + 1 ; j < n ; j++){
                l = lcm(l , nums[j]);
                g = gcd(g , nums[j]);
                prod *= nums[j] * 1LL;

                if(prod == (l * g)){
                    res = max(res , j - i + 1);
                }
            }
        }

        return res;
    }
};