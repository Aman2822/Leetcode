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
        
        return arr[n - 1];
    }
};