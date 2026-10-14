class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        int temp = sum;

        vector<int> ans(num, 0);

        for (int i = 0; i < num; i++) {
            if (sum < 10) {
                ans[i] = sum;
                break;
            } else {
                ans[i] = 9;
                sum -= 9;
            }
        }

        string result = "";
        for(int i = 0 ; i < ans.size() ; i++){
            result += to_string(ans[i]);
        }
        
        long long sum1 = 0;
        for(int i = 0 ; i < result.length() ; i++){
            sum1 += (result[i] - '0');
        }

        if(sum1 == temp) return result;

        return "";
    }
};