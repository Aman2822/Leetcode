class Solution {
public:
    int maximumProduct(vector<int>& nums) {
       int n = nums.size();
       sort(nums.begin() , nums.end());
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

       int option1 = nums[0] * nums[1] * nums[n-1];
       int option2 = nums[n-1] * nums[n-2] * nums[n-3];

       return max(option1 , option2);

       

    }
};