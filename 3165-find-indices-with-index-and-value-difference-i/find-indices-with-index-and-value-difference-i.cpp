class Solution {
public:
    vector<int> findIndices(vector<int>& nums, int indexDifference, int valueDifference) {
        int n = nums.size();
        vector<int> ans = {-1 ,-1};

        for(int i = 0 ; i < n ; i++){
            for(int j = i+indexDifference ; j < n ; j++ ){
                int diff = abs(nums[i] - nums[j]);
                if(diff >= valueDifference){
                    ans[0] = i;
                    ans[1] = j;
                    break;
                }
            }
        }

        return ans;
    }
};