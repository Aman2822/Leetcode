class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        int sum = 0;

        for(int i = 0 ; i<n;i++){
           for(int j=i ; j < n; j++){
              sum += nums[j];
              if(sum == k) count++;
           }
           sum = 0;
        }
        return count++;
    }
};