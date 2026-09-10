class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        // unordered_map<int , int> mp;

        // for(int i = 0 ; i < n ; i++ ){
        //     mp[arr[i]]++;
        // }
        // int i = 1;
        // int ans = -1;
        // while(k > 0){
        //     if(mp.find(i) == mp.end()){
        //         ans = i;
        //         k--;
        //     }
        //     i++;
        // }

        // return ans;

        //Binary Search
        int low = 0 , high = n - 1;

        while(low <= high){
            int mid = low + (high - low) / 2;

            int missing = arr[mid] - (mid+1);    //Missing integers upto mid index

            if(missing < k){
                low = mid + 1;
            }
            else{
                high = mid - 1;
            }
        }

        return high + k + 1;               //arr[high] + more    more = (k- missing)

    }
};