class Solution {
public:
    typedef long long ll;
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();

        vector<ll> prefixGCD(n,0);

        int max_ele = nums[0] ;
        prefixGCD[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            max_ele = max(max_ele , nums[i]);
            prefixGCD[i] = __gcd(max_ele, nums[i]);
        }
        
        sort(prefixGCD.begin() , prefixGCD.end());

        int i = 0 ;
        int j = n - 1;
        ll sum = 0;

        while(i < j){
            sum += __gcd(prefixGCD[i] , prefixGCD[j]);
            i++;
            j--;
        }
        return sum;

    }
};