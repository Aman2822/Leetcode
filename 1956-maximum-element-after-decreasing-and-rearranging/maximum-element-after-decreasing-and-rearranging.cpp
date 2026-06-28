class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        int n = arr.size();
        sort(arr.begin(), arr.end());
        int abs_check ;

        for(int i = 0 ; i < n ; i++){
            if(i == 0){
                arr[i] = 1;
            }
            else {
            abs_check = abs(arr[i] - arr[i-1]);
            if(abs_check > 1){
               arr[i] = arr[i-1]+ 1;
            }
            } 

        }
        int max_El = INT_MIN;
        for(int i = 0 ; i < n ; i++){
            max_El = max(max_El, arr[i]);
        }
        return max_El;
    }
};