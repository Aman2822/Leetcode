class Solution {
public:
    int candy(vector<int>& ratings) {
    //     int n = ratings.size();
    //     vector<int> left(n);
    //     vector<int> right(n);

    //    //Approach 1 

    //    //This satisfy left neighbours only
    //     for(int i = 0 ; i < n ; i++){
    //         if(i == 0) left[i] = 1;
    //         else{
    //             if(ratings[i] > ratings[i-1]){
    //                 left[i] = left[i-1] + 1;
    //             }
    //             else left[i] = 1;
    //         }
    //     }

    //     //This satisfy right neighbor only;
    //     for(int i = n-1 ; i >= 0 ; i--){
    //         if(i == n - 1) right[i] = 1;
    //         else{
    //             if(ratings[i] > ratings[i+1]){
    //                 right[i] = right[i+1] + 1;
    //             }
    //             else right[i] = 1;
    //         }
    //     }

    //     //Take max to satisfy both neighbor
    //     int candies = 0;

    //     for(int i = 0 ; i < n ; i++){
    //         candies += max(left[i] , right[i]);
    //     }

    //     return candies;

    //Approach 2 - will optimize the right block and reduce time and space complexity by N
        int n = ratings.size();
        vector<int> left(n);
        left[0] = 1;

       //Approach 1 

       //This satisfy left neighbours only
        for(int i = 1 ; i < n ; i++){
            if(ratings[i] > ratings[i-1]){
                left[i] = left[i-1] + 1;
            }
            else left[i] = 1;
        }

        //This curr element will satisfy right and directly we take max and do sum
        int curr = 1 , sum = max(1 , left[n-1]);
        cout << sum << endl;
        for(int i = n - 2 ; i >= 0 ; i--){
            if(ratings[i] > ratings[i+1]){
                curr++;
            }
            else{
                curr = 1;
            }
            sum += max(left[i] , curr);
        }

        return sum;


    }
};