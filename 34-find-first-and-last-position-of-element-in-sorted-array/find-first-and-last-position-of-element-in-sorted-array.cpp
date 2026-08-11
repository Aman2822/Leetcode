class Solution {
public:
    // int lower(vector<int>& nums , int target){
    //     int n = nums.size();
    //     int low = 0 , high = n - 1;
    //     int ans = n;

    //     while(low <= high){
    //         int mid = low + (high - low)/2;
    //         if(nums[mid] >= target){
    //             ans = mid;
    //             high = mid - 1;
    //         }
    //         else{
    //            low = mid + 1;
    //         }
    //     }
    //     return ans;
    // }

    // int upper(vector<int>& nums , int target){
    //     int n = nums.size();
    //     int low = 0 , high = n - 1;
    //     int ans = n;

    //     while(low <= high){
    //         int mid = low + (high - low)/2;
    //         if(nums[mid] > target){
    //             ans = mid;
    //             high = mid - 1;
    //         }
    //         else{
    //             low = mid + 1;
    //         }
    //     }
    //     return ans;
    // }
    
    int first(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0 , high = n - 1;
        int index = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                index = mid;
                high = mid - 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return index;
    }

    int last(vector<int>& nums, int target){
        int n = nums.size();
        int low = 0 , high = n - 1;
        int index = -1;

        while(low <= high){
            int mid = low + (high-low)/2;
            if(nums[mid] == target){
                index = mid;
                low = mid + 1;
            }
            else if(nums[mid] > target){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return index;
    }


    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        // int i = 0 , j = n-1;
        // vector<int> result(2 ,-1);

        // while(i < n){
        //     if(nums[i] == target){
        //         result[0] = i;
        //         break;
        //     }
        //     i++;
        // }
        // for(int k = n-1; k >=i ; k--){
        //     if(nums[k] == target){
        //         result[1] = k;
        //         break;
        //     }
        // }

        // return result;
        

        //Implementing lower bound and upper bound

        // if( n == 0) return {-1,-1};
        // int lb = lower(nums , target );

        // if( lb == n || nums[lb] != target ){
        //     return {-1,-1};
        // }

        // int up = upper(nums, target) - 1;

        // return {lb, up};

      
        // Without implementing lower and upper bound

        if(n == 0) return {-1,-1};

        int f_occur = first(nums , target);
        if(f_occur == -1) return {-1,-1};
        int l_occur = last(nums, target);

        return {f_occur , l_occur};



    }
};