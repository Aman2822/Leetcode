class Solution {
public:
    int sum(int n){
        int ans = 0;

        while(n > 0){
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
    int smallestIndex(vector<int>& nums) {
        int n = nums.size();

        for(int i = 0 ; i < n ; i++){
            int val = sum(nums[i]);
            if(val == i){
                return i;
            }
        }

        return -1;
    }
};