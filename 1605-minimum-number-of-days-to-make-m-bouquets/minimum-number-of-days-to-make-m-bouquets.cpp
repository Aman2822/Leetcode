class Solution {
public:
    int bouquets(vector<int>& bloomDay, int day , int bouquet,  int flowergrowed) {
       int n = bloomDay.size();

       int total_bouq = 0;
       int consecutive_flower  = 0;

       for(int i = 0 ; i < n ; i++){
        if(bloomDay[i] <= day){
           consecutive_flower++;

           if(consecutive_flower == flowergrowed){
            total_bouq++;
            consecutive_flower = 0;
           }
        }
        else{
            consecutive_flower = 0;
           }
       }

       if(total_bouq >= bouquet) return total_bouq;
       else return -1;

       
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int maxi = *max_element(bloomDay.begin(), bloomDay.end());

        // bool days = false;
        // int idx = -1;

        // for (int i = mini; i <= maxi; i++) {
        //     days = bouquets(bloomDay, i , m  , k);

        //     if(days == true){
        //         idx = i;
        //         break;
        //     }
        // }

        // return idx;

        //Binary Search
        int low = mini , high = maxi;
        int ans = -1;

        while(low <= high){
            int mid = low + (high - low)/2;

            int currbouquet = bouquets(bloomDay , mid , m , k);

            if(currbouquet >= m){
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