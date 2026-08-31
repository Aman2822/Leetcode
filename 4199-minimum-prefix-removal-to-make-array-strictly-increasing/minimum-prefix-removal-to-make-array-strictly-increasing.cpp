class Solution {
public:
    int minimumPrefixLength(vector<int>& nums) {
        int n = nums.size();
        int check = 0;

        for(int j =  n-1 ; j > 0 ;j--){
            if(nums[j] <= nums[j-1]){
                check = j;
                break;
            }
        }

        // if(check == 0) return check;

        // int ans = n-check;

        return check;



    }
};