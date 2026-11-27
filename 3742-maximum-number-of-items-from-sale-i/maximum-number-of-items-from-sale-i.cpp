class Solution {
public:
//knapsack problem
    // int t[1001][1501];

    // int solve(int n , int budget , int minprice , vector<int>& factor , vector<vector<int>>& items){

    //     if(n == 0){
    //         return budget/minprice;
    //     }

    //     if(t[n][budget] != -1){
    //         return t[n][budget];
    //     }

    //     int take = 0;
    //     int skip = 0;
    //     int price = items[n-1][1];

    //     if(price <= budget){
    //        take = 1 + factor[n-1] + solve(n-1 , budget - price , minprice , factor , items);
    //     }

    //     skip = solve(n-1 , budget , minprice , factor , items);

    //     return t[n][budget] = max(take , skip);
    // }

    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        int minprice = INT_MAX;

        // precompute the factor
        vector<int> factor;
        for (int i = 0; i < n; i++) {
            minprice = min(minprice , items[i][1]);
            int rem = items[i][0];
            int fac = 0;

            for (int j = 0; j < n; j++) {
                if (j != i) {
                    if (items[j][0] % rem == 0) {
                        fac++;
                    }
                }
            }

            factor.push_back(fac);
        }

        // memset(t , -1 , sizeof(t));

        // return solve(n , budget , minprice ,  factor , items);

        

        //Approach 2 - Tabulation Bottom up

        vector<vector<int>> t(n+1 , vector<int>(budget+1 , 0));

        for(int b = 0 ; b <= budget ; b++){
            t[0][b] = b/minprice;
        }

        for(int i = 1 ; i <= n ; i++){
            for(int b = 0 ; b <= budget ; b++){
                int item = items[i-1][1];
                int take = 0;

                if(item <= b){
                  take = 1+ factor[i-1] + t[i-1][b-item]; 
                }

                int skip = t[i-1][b];

                t[i][b] = max(take,skip);
            }
        }

        return t[n][budget];

       
    }
};