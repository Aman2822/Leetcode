class Solution {
public:
    //typedef long long ll;
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        //int n = nums.size();
        // vector<ll> gcd;

        // //Gcd pairs
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i + 1 ; j < n ; j++){
        //        gcd.push_back(__gcd(nums[i],nums[j]));
        //     }
        // }

        // //Sorted
        // sort(gcd.begin() , gcd.end());

        // vector<int> ans;
        // ll q = queries.size();
        // ll p = gcd.size();
        
        // for(int i = 0 ; i < q; i++){
        //     int query = queries[i];

        //     ans.push_back(gcd[query]);

        // }
        // return ans;

        int n = nums.size();
        int max_ele =  *max_element(nums.begin() , nums.end());

        vector<long long> count_divisors(max_ele+1 ,0);
        for(int i = 0 ; i < n ;i++){
            int num = nums[i];

            for(int j = 1 ; j*j <=num ;j++){
                if(num % j == 0){
                    count_divisors[j]++;

                    if(num/j != j){
                    count_divisors[num/j]++;
                    }
                }
            }
        }

        vector<long long> count_minpairs(max_ele+1 ,0);
        for(int i = max_ele ; i >=1 ;i--){
            long long count = count_divisors[i];

            count_minpairs[i] = count * (count-1) / 2;

            for(int mult = 2 * i ; mult <=max_ele ; mult += i){
                count_minpairs[i] -= count_minpairs[mult];
            }
        }

        vector<long long> prefixGcd(max_ele+1 , 0);
        for(int i = 1 ; i <= max_ele ; i++){
            prefixGcd[i] = prefixGcd[i-1] + count_minpairs[i];
        }

        vector<int> result;
        int q = queries.size();

        for(long long i = 0 ; i < q ; i++){
            int l = 1 , r = max_ele ;
            int temp = 1;

            while(l <= r){
                int mid_gcd = l + (r-l)/2;
                if(prefixGcd[mid_gcd] > queries[i]){
                    temp = mid_gcd;
                    r = mid_gcd - 1;
                }
                else{
                    l = mid_gcd + 1;
                }
            }
            result.push_back(temp);
        }
        
        return result;


    }
};