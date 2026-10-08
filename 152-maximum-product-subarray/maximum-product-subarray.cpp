class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        int maxprod = INT_MIN;

        // //Subarray ka ques hai toh sliding window lagta hai lekin yaha pe negative elements hai toh sliding window nhi lagega

        // int i = 0 , j = 0;

        // while(j < n){
        //     int curr = maxProd * nums[j];
        //     cout << curr << endl;
        //     while(i < j && curr < maxProd){
        //         maxProd = maxProd/nums[i];
        //         cout << "maxProd : " << maxProd << endl; 
        //         i++;
        //     }

        //     if(curr >= maxProd){
        //        maxProd = max(maxProd , curr);
        //     }

        //     j++;
        // }


        // return maxProd;

        for(int i = 0 ; i < n ; i++){
            int prod = 1;
            for(int j = i ; j < n ; j++){
                prod *= nums[j];
                maxprod = max(maxprod , prod);
            }
        }


        return maxprod;

        
    }
};