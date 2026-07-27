class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n = nums.size();
        //    sort(nums.begin() , nums.end());
        //    int i = 0 , j = n - 1 , count = 0;
        //    int first , second , third;

        //   if(abs(nums[i]) > abs(nums[j])){
        //     first = nums[i];
        //     i++;
        //     count++;
        //    }
        //    else{
        //     first = nums[j];
        //     j--;
        //    }

        //    if(abs(nums[i]) > abs(nums[j])){
        //     second = nums[i];
        //     i++;
        //     count++;
        //    }
        //    else{
        //     second = nums[j];
        //     j--;
        //    }

        //    if(count != 2){
        //       if(abs(nums[i]) > abs(nums[j])){
        //         third = nums[i];
        //       }
        //    }
        //    else{
        //      third = nums[j];
        //    }

        //    return first * second * third;

        //    int option1 = nums[0] * nums[1] * nums[n-1];
        //    int option2 = nums[n-1] * nums[n-2] * nums[n-3];

        //    return max(option1 , option2);

        int max1 = INT_MIN;
        int max2 = INT_MIN;
        int max3 = INT_MIN;

        for(int i = 0 ; i < n ; i++){
            if(max1 < nums[i]){
                max3 = max2;
                max2 = max1;
                max1 = nums[i];
            }
            else if(max2 < nums[i]){
                max3 = max2;
                max2 = nums[i];
            }
            else if(max3 < nums[i]){
                max3 = nums[i];
            }
        }

        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i = 0 ; i < n ; i++){
            if(min1 > nums[i] ){
                min2 = min1;
                min1 = nums[i];
            }
            else if(min2 > nums[i]){
                min2 = nums[i];
            }
        }

        int option1 = max1 * max2 * max3;
        int option2 = max1 * min1 * min2;

        return max(option1 , option2);
    }
};