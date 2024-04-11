class Solution {
    public int searchInsert(int[] nums, int target) {
        int count = 0;
        int i = 0;
        while(i<nums.length && nums[i]<target){
            count++;
            i++;
        }
        return count;
    }
}