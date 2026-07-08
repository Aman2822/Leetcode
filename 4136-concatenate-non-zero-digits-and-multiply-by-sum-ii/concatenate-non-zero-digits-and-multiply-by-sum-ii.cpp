class Solution {
public:
    typedef long long ll;
    int MOD = 1e9 + 7;

    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();

        vector<ll> digitSum(n,0);
        vector<ll> numberUpto(n,0);
        vector<int> nonZerodigit(n,0);
        vector<ll> power(n+1 ,0);
        
        digitSum[0] = s[0] -'0';
        for(int i = 1 ; i < n ;i++){
            int digit = s[i] -'0';
            if(digit != 0) digitSum[i] = (digitSum[i-1] + digit) % MOD;
            else digitSum[i] = digitSum[i-1]; 
        }

        numberUpto[0] = s[0] -'0';
        for(int i = 1 ; i  < n ;i++){
            int digit = s[i] - '0';
            if(digit != 0) numberUpto[i] = ((numberUpto[i-1] * 10) + digit) % MOD;
            else numberUpto[i] = numberUpto[i-1];
        }

        power[0] = 1;
        for(int i = 1 ; i < n ; i++ ){
            power[i] = (power[i-1] * 10) % MOD;
        }

        nonZerodigit[0] = (s[0] != '0') ? 1:0;
        for(int i = 1 ; i < n ; i++ ){
            int digit  = s[i] - '0';
            if(digit != 0) nonZerodigit[i] = nonZerodigit[i-1] + 1;
            else  nonZerodigit[i] = nonZerodigit[i-1];
        }

        int q = queries.size();
        vector<int> result(q);
        for(int i = 0 ; i < q ; i++){
            int l = queries[i][0];
            int r = queries[i][1];

           ll sum = digitSum[r] - ((l == 0) ? 0 : digitSum[l-1]);

           int k = nonZerodigit[r] - ((l == 0) ? 0 : nonZerodigit[l-1]);

           int numBefore  = (l == 0) ? 0 : numberUpto[l-1];

           ll x = (numberUpto[r] - (numBefore * power[k] % MOD)  + MOD) % MOD;          

           result[i] = (int)((x * sum) % MOD);
        }

        return result;


        

    }
};