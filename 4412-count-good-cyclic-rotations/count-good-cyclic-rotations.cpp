class Solution {
public:
    typedef long long ll;
    int countGoodRotations(vector<int>& nums) {
        int n = nums.size();
        ll total = 0;

        for(int num : nums){        //Calculate the total sum of array
            total += num;
        }

        //Calculate the first window size element 0...k-1 (k= n/2);
        ll k = n/2;
        ll firstpart = 0;

        for(int i = 0 ; i < k ; i++){
            firstpart += nums[i];
        }

        int ans = 0;

        //Now traverse the array 
        for(int i = 0 ; i < n ; i++){
            ll secondpart = total - firstpart;  //Secondpart

            if(firstpart > secondpart){
                ans++;
            }
            
            //This is cutting from window
            ll outgoing = nums[i];
            ll incoming = nums[(i+k) % n];
            
            //Firstpart calculating window sum
            firstpart = firstpart - outgoing + incoming; 
        }

        return ans;




    }
};