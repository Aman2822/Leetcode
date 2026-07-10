class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m  = matrix.size();
        int n = matrix[0].size();
        vector<int> spiral;

        int left = 0 , right = n - 1;
        int top = 0 , bottom = m - 1;

        while(top <= bottom && left <= right ){

            //right traversal
            for(int i = left ; i <=right ; i++){
                spiral.push_back(matrix[top][i]);
            }
            top++;

            //down Traversal
            for(int i = top ; i <=bottom ; i++ ){
                spiral.push_back(matrix[i][right]);
            }
            right--;

            //left traversal
            if(top <= bottom){
                for(int i = right ; i >=left ; i--){
                    spiral.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
    


            //up traversal
            if(left <= right){
                for(int i = bottom ; i >= top ;i--){
                    spiral.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return spiral;


          


        
    }
};