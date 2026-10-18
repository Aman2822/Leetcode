class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int rows = mat.size();
        int cols = mat[0].size();

        if(r * c != rows * cols) return mat;

        vector<vector<int>> reshape(r , vector<int>(c , 0));

        vector<int> val;
        for(int i = 0 ;i < rows ; i++){
            for(int j = 0 ; j < cols ; j++ ){
                val.push_back(mat[i][j]);
            }
        } 
        
        int k = 0;
        for(int i = 0 ; i < r ; i++){
            for(int j = 0 ; j < c ; j++){
                reshape[i][j] = val[k];
                k++;
            }
        }

        return reshape;
    }
};