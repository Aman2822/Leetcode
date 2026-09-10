class Solution {
public:
    vector<int> generatecurrRow(int row){
       vector<int> ans;
       ans.push_back(1);

       long long result = 1;

       for(int col = 1 ; col < row ; col++){
        result = result * (row - col);
        result = result / col;

        ans.push_back(result);
       }

       return ans;
    }

    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;

        for(int i = 1 ; i <= numRows ; i++){
            vector<int> currRow = generatecurrRow(i);
            pascal.push_back(currRow);
        }

        return pascal;

        
    }
};