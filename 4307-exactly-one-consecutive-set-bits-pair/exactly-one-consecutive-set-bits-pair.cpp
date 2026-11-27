class Solution {
public:
    bool consecutiveSetBits(int n) {
        string ans = "";
        if( n <= 2) return false;

        while(n != 1){
            if(n % 2 == 1){
                ans += '1';
            }
            else ans +=  '0';
            n = n/2;
        }
        ans += '1';
        reverse(ans.begin() , ans.end());

        int cnt = 0;

        for(int i = 1 ; i < ans.length() ; i++){
            if(ans[i] == '1' && ans[i-1] == '1'){
                cnt++;
            }
        }

        if(cnt == 1) return true;

        return false;
    }
};