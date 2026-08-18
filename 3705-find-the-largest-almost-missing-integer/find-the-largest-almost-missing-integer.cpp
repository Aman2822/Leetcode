class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        
        // Sliding window problem - Approach 1
        int i = 0 , j = 0;

        unordered_map<int , int> mp; // to get the count of the numbers
        unordered_set<int>st;  // to store the subarrays

        while(j < n){
            if(j-i+1 == k){
              // Insert the subarray into set
              for(int p = i ; p <= j ; p++){
                st.insert(nums[p]);
              }
              //Take the count of the integers into the set
              for(int x : st){
                mp[x]++;
              }
              //Shifting window
              st.erase(nums[i]);
              i++;
            }
            j++;
        }

        int result = -1;
        //Take num(key) and count(value) from map
        for(auto[num , count] : mp){
            if(count == 1 && num > result){
                result = num;
            }
        }

        return result;
    }
};