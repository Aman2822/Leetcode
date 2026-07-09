class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 , j = n-1;
        vector<int> result(2 ,-1);

        while(i < n){
            if(nums[i] == target){
                result[0] = i;
                break;
            }
            i++;
        }
        for(int k = n-1; k >=i ; k--){
            if(nums[k] == target){
                result[1] = k;
                break;
            }
        }

        return result;


    }
};