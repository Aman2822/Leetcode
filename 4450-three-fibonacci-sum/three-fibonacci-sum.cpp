class Solution {
public:
    typedef long long ll;
    bool threeFibonacciSum(int n) {
        vector<ll> pref(45 , 0);
        pref[0] = 0;
        pref[1] = 1;

        for(int i = 2 ; i < 45 ; i++){
            pref[i] = pref[i-1] + pref[i-2];
        }

        ll i = 0 , j = 1 , k = 2;
        if(n == 1) return false;
        ll sum = pref[i] + pref[j] + pref[k];

        while(sum < n){
            sum = pref[i] + pref[j] + pref[k];
            i++;
            j++;
            k++;
        }

        if(n != sum){
           return false;
        }


        return true;
        
    }
};