class Solution {
    public int search(int[] nums, int target) {
        int start= 0;
        int end = nums.length-1;
        while(start<=end){
            int m = start +(end-start)/2;
       
        if(nums[m]==target){
            return m;
        }if(nums[m]<target){
            start = m+1;
        }
        else{
            end=m-1;
        }
        }
        return -1;

        }
    }
