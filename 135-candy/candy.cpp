class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> left(n);
        vector<int> right(n);


       //This satisfy left neighbours only
        for(int i = 0 ; i < n ; i++){
            if(i == 0) left[i] = 1;
            else{
                if(ratings[i] > ratings[i-1]){
                    left[i] = left[i-1] + 1;
                }
                else left[i] = 1;
            }
        }

        //This satisfy right neighbor only;
        for(int i = n-1 ; i >= 0 ; i--){
            if(i == n - 1) right[i] = 1;
            else{
                if(ratings[i] > ratings[i+1]){
                    right[i] = right[i+1] + 1;
                }
                else right[i] = 1;
            }
        }

        //Take max to satisfy both neighbor
        int candies = 0;

        for(int i = 0 ; i < n ; i++){
            candies += max(left[i] , right[i]);
        }

        return candies;


    }
};