class Solution {
    public int findNonMinOrMax(int[] nums) {
        int n = nums.length;
        if(n == 0 || n==1 || n==2){
            return -1;
        }
        else{
            Arrays.sort(nums);
            return nums[1];
        }
    }
}