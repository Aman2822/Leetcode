class Solution {
public:
    int minimumSumSubarray(vector<int>& nums, int l, int r) {
        int n = nums.size();
        int min_sum = INT_MAX;

       for(int i = 0 ; i < n ; i++){
         for(int j = 0 ; j < n ; j++){
            int len = j-i+1;
            int sum = 0;
            if(len >= l && len <= r){
               for(int k = i ; k <= j ; k++){
                sum += nums[k];
               }
            }
            else continue;
            if(sum > 0){
                min_sum = min(min_sum , sum);
            }
         }
       }

       if(min_sum == INT_MAX) return -1;
       else return min_sum ;
    }
};