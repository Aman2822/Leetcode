class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        long long score = 0;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] < 0) nums[i] = abs(nums[i]);
        }

        sort(begin(nums) , end(nums));

        int i = 0 , j = n- 1;

        while(i < j){
            score += (nums[j] * nums[j]);
            score -= (nums[i] * nums[i]);
            i++;
            j--;
        }

        if(n % 2 == 1){
            score += (nums[i] * nums[i]);
        }
        

        return score;
    }
};