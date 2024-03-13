class Solution {
    public int pivotInteger(int n) {
        for(int x = 1; x<=n; x++){
            long left_sum = (x*(x+1))/2;
            long right_sum = (n*(n+1))/2 - (x*(x-1))/2;

            if(left_sum == right_sum) return x;
        }
        return -1;
    }
}