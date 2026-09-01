class Solution {
public:
    typedef long long ll;
    ll MOD = 1e9 + 7;

    ll power(ll base , ll exponent){
        ll res = 1;
        base %= MOD;

        while(exponent > 0){
            if(exponent % 2 == 1){
                res = (res * base) % MOD;
                exponent -= 1;
            }
            else{
                base = (base * base) % MOD;
                exponent /= 2;
            }
        }
        return res;
    }

    ll even(ll n){
      ll odd = n/2;
      
      ll calculate1 = power(4,odd) % MOD;
      ll calculate2 = power(5,odd) % MOD;

      return (calculate1 * calculate2) % MOD;

    }

    ll odd(ll n ){
        ll even_idx = (n+2-1)/2;
        ll odd_idx = n/2;

        ll calculate1 = power(4,odd_idx) % MOD;
        ll calculate2 = power(5,even_idx) % MOD;
 
        return (calculate1 * calculate2) % MOD;

    }

    int countGoodNumbers(long long n) {
        ll temp = n;
        ll good = 0;

        if(n % 2 == 0){
            return even(n);
        }
        return odd(n);
    }
};