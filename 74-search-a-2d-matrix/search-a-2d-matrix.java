class Solution {
    public boolean searchMatrix(int[][] matrix, int target) {
        int row = matrix.length;
        if(row == 0){
            return false;
        }
        int column = matrix[0].length;{
            if(column == 0){
                return false;
            }
        }
        int start = 0;
        int end = column-1;

        while(start<row && end>=0){
            if(matrix[start][end] == target){
                return true;
            }
            else if(target < matrix[start][end]){
                end--;
            }else{
                start++;
            }
        }
        return false;
    }
}