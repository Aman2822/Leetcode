class Solution {
public:
    typedef long long ll;

    long long countCommas(long long n) {

        //Approach - 1
        //10^3 -- 10^6 - 1 = 1 comma
        //10^6  -- 10^9 - 1 = 2 comma
        ll result = 0;

        ll lower = 1000;
        ll commas = 1;

        while(lower <= n){
            ll upper = (lower * 1000) - 1;
            //we have calculate the uppermost range and we have cal. to n therefore upper = n;
            if(upper > n) {  
                upper = n;
            }

            ll range = upper - lower + 1;

            result += (range * commas);
            lower *= 1000;
            commas++;
        }

        return result;
    }
};