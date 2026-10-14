class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int temp = sum;

        string ans(num, '0');

        for (int i = 0; i < num; i++) {
            if (sum < 10) {
                ans[i] = sum + '0';
                break;
            } else {
                ans[i] = '9';
                sum -= 9;
            }
        }

        long long sum1 = 0;
        for(int i = 0 ; i < ans.length() ; i++){
            sum1 += (ans[i] - '0');
        }

        if(sum1 == temp) return ans;

        return "";
    }
};