class Solution {
public:
    bool strictly(vector<int>& nums , int start , int i){
        int n = nums.size();

        for(int idx = start ; idx < i ; idx++){
            if(nums[idx] >= nums[idx+1]){
                return false;
            }
        }

        return true;
    }

    bool decr(vector<int>& nums , int mid , int j){
        int n = nums.size();

        for(int idx = mid ; idx < j ; idx++){
            if(nums[idx] <= nums[idx+1]){
                return false;
            }
        }

        return true;
    }


    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n == 3) return false;

        for(int i = 1 ; i < n - 2 ; i++){
            bool flag = strictly(nums , 0 , i);
            if(flag){
                for(int j = i+1  ; j < n - 1 ; j++){
                    bool flag1 = decr(nums , i , j);
                    if(flag1){
                        if(strictly(nums , j , n-1)){
                            return true;
                        }
                    }

                }
            }
        }

        return false;
    }
};