class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();

        // // Sliding window problem - Approach 1
        // int i = 0 , j = 0;

        // unordered_map<int , int> mp; // to get the count of the numbers
        // unordered_set<int>st;  // to store the subarrays

        // while(j < n){
        //     if(j-i+1 == k){
        //       // Insert the subarray into set
        //       for(int p = i ; p <= j ; p++){
        //         st.insert(nums[p]);
        //       }
        //       //Take the count of the integers into the set
        //       for(int x : st){
        //         mp[x]++;
        //       }
        //       //Shifting window
        //       st.erase(nums[i]);
        //       i++;
        //     }
        //     j++;
        // }

        // int result = -1;
        // //Take num(key) and count(value) from map
        // for(auto[key , times] : mp){
        //     if(times == 1 && key > result){
        //         result = key;
        //     }
        // }

        // return result;

        // Approach 2 - Observation

        // If k==n then largest number is the ans because only one subarray
        // possible
        if (k == n) {
            return *max_element(nums.begin(), nums.end());
        }

        vector<int> freq(51, 0);
        for (int i = 0; i < n; i++) {
            freq[nums[i]]++;
        }

        // If k == 1 means one size subarray then we have to select max possible
        // value that has freq == 1
        if (k == 1) {
            for (int i = 50; i >= 0; i--) {
                if(freq[i] == 1){
                    return i;
                }
            }
            return -1;
        }

        // If 1<k<n then two cases: because except first and last element all element appears in an subaarray twice

        int max_no = -1;
        //1st element is max element
        if(freq[nums[0]] == 1){
           max_no =  max(max_no , nums[0]);
        }

        // last element is max element 
        if(freq[nums[n-1]] == 1){
            max_no = max(max_no, nums[n-1]);
        }

        return max_no;

        
    }
};