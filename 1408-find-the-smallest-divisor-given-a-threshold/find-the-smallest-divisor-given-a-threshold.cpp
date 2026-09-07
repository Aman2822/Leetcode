class Solution {
public:
    int sum(vector<int>& nums, int currdiv){
       int n = nums.size();
       int ans = 0;

       for(int i = 0 ; i < n ; i++){
        ans += ceil((double)nums[i] / (double)currdiv);
       }

    //    cout << ans << endl;

       return ans;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        // int mini = *min_element(nums.begin() , nums.end());
        int maxi = *max_element(nums.begin() , nums.end());

        // for(int i = 1 ;i <= maxi ; i++){            //TLE
        //    int currsum = sum(nums, i);

        //    if(currsum <= threshold ){
        //     return i;
        //    }
        // }

        // return maxi;

        //Binary Search
        int low = 1 , high = maxi;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int currsum = sum(nums, mid);

            if(currsum <= threshold ){
                ans = mid;
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }

        return ans;
    }
};