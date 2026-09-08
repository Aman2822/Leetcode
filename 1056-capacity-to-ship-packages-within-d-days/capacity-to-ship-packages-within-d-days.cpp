class Solution {
public:
    typedef long long ll;
    int weight(vector<int>& weights , int curr , int days){
        int n = weights.size();
        int requiredDay = 1;
        int temp = curr;

        int i = 0;
        while( i < n){
            if(weights[i] <= curr){
               curr -= weights[i];
               i++;
            }
           else{
            requiredDay++;
            curr = temp;
           }
        }

        // cout << requiredDay << endl;

        return requiredDay;
    }


    int shipWithinDays(vector<int>& weights, int days) {
        int maxi = *max_element(weights.begin() , weights.end());  //Start

        ll sum = 0;

        for(int i = 0 ; i < weights.size() ; i++){
            sum += weights[i];
        }

        // for(int i = maxi ; i <= sum ; i++){
        //     int requiredWeight = weight(weights, i , days);

        //     if(requiredWeight <= days){
        //         return i;
        //     }
        // }

        int low = maxi , high = sum;
        int ans  = -1;
        while(low <= high){
            int mid = low + (high - low)/2;

            int requiredDay = weight(weights , mid , days);
            
            //When the currday is less than or equal to days then we can go left into the range see if another smaller value is acceptable
            if(requiredDay <= days){  
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