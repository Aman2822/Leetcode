class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int maxi = INT_MIN , mini = INT_MAX;
        int max_idx = -1 , min_idx = -1;

        if(n == 1) return 1;

        for(int i = 0 ; i < n ; i++){
            if(nums[i] > maxi){
                maxi = nums[i];
                max_idx = i;
            }
            if(nums[i] < mini ){
                mini = nums[i];
                min_idx = i;
            }
        }

        // int frontopn = 0;
        // if(max_idx > min_idx){
        //     frontopn = max_idx+1;
        // }
        // else{
        //     frontopn = min_idx + 1;
        // }

        // int backopn = 0;
        // if(max_idx > min_idx){
        //     backopn = min_idx + 1;
        // }
        // else{
        //     backopn = max_idx + 1;
        // }

        // // int opn = frontopn + backopn;
        // // int i = 0 , j = n-1;
        // int maxc = -1 , minc = -1;
        // while(i < j){
        //     if(maxc != -1 && minc != -1){
        //         break;
        //     }
        //     if(mini ==  nums[i]) minc= i;
        //     if(mini == nums[j]) minc = j;
        //     if(maxi == nums[i]) maxi = i;
        //     if(maxi == nums[j]) maxi = j;

        //     opn += 2;          
        // }

        // // int frontopn =  max(min_idx + 1 , max_idx  + 1);
        // // cout << frontopn << endl;
        // // int backopn = min(min_idx + 1 , max_idx + 1);
        // // cout << backopn << endl;

        // int bothopn = (backopn+1) + (n-frontopn);
        // // cout << bothopn << endl;

        // int left = max(max_idx , min_idx) + 1;
        // int right = n - min(max_idx , min_idx);  //8-(2,1)
        // int left_right = (n - right) + left;
        // return min({left , right , left_right});

        int left = min(max_idx , min_idx);
        int right =  max(max_idx , min_idx);

        return min({right+1 , n-left , (left+1+n-right)});


    }
};