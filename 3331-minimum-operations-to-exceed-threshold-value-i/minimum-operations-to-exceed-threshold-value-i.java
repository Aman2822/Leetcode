class Solution {
    public int minOperations(int[] nums, int k) {
        int counter = 0;
        for(int i : nums){
            if( i < k){
                counter++;
            }
        }
        return counter;
    }
}