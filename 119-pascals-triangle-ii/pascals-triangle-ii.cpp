class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> pascal;

        long long result = 1;
        pascal.push_back(1);

        for(int col = 1 ; col < rowIndex ; col++){
            //Rowindex+1 because it is 0th indexed
            result = result * (rowIndex + 1 - col);
            result = result / col;
            pascal.push_back(result);
        }

        if(rowIndex > 0){
            pascal.push_back(1);
        }

        return pascal;

    }
};