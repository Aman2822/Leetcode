class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max_water = INT_MIN;

        //Brute force
        
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = i+1 ; j < n ; j++){
        //         int min_height = min(height[i] , height[j]);
        //         int distance = j - i ;
        //         int water = min_height * distance;
        //         max_water = max(max_water , water );
        //     }
        // }
        
        // return max_water;

        //Optimize approach
        int i = 0 , j = n-1;
        int min_height = 0;
        // while(i < j){
        //     if(height[i] < height[j]){
        //        min_height = height[i]*(j-i);
        //        i++;
        //     }
        //     else if(height[i] > height[j]){
        //         min_height = height[j] * (j-i);
        //         j--;
        //     }
        //     else{
        //         min_height =  height[i]*(j-i);
        //         i++;
        //         j--;
        //     }
        //     max_water = max(max_water , min_height);
        // }

        // return max_water;

        //Code clean and optimal

        while( i < j){
            int min_height = min(height[i] , height[j]);
            int width = j - i;
            max_water = max(max_water , min_height*width);
            if(height[i] > height[j]){
                j--;
            }
            else if(height[i] < height[j]){
                i++;
            }
            else{
                i++;
                j--;
            }
        }
        return max_water;
        
    }
};