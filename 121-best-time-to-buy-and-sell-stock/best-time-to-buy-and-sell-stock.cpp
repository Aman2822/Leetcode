class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int max_profit = 0;
        int i = 0 , j = 1;

        while(j != n){
            if(prices[i] < prices[j] ){
                int today_profit = prices[j] - prices[i];
                max_profit = max(today_profit , max_profit);
                j++;
            }
            else{
                i=j;
                j++;
            }
        }
        return max_profit;

      
    }
};