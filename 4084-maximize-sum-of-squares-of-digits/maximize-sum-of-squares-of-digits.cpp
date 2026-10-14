class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        // int temp = sum;
        if(sum > num * 9) return "";

        string ans(num, '0');

        for (int i = 0; i < num; i++) {
            if (sum > 9) {
                ans[i] = '9';
                sum -= 9;
            } else {
                ans[i] = sum + '0';
                break;
            }
        }

        // long long sum1 = 0;
        // for(int i = 0 ; i < ans.length() ; i++){
        //     sum1 += (ans[i] - '0');
        // }

        // if(sum1 == temp) return ans;

        // return "";

        return ans;
    }
};