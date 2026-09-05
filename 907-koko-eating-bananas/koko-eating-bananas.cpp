class Solution {
public:
    typedef long long ll;
    ll helper(vector<int>& piles , int hourly){
        ll sum = 0;

        for(int i = 0 ; i < piles.size() ; i++){
            //sum += (piles[i] + hourly - 1) / hourly;
            sum +=  ceil((double) piles[i] /(double) hourly);
        }

        // cout << sum << endl;

        return sum;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        int maxi = *max_element(piles.begin() , piles.end());

        //Binary Search 
        int low = 1 , high = maxi;

        while(low <= high){
            int mid = low + (high - low)/2;

            ll requireTime = helper(piles, mid);

            if(requireTime <= h){
                high = mid - 1;
            }
            else{
                low = mid + 1;
            }
        }
        return low;

    }
};