class Solution {
    public int xorOperation(int n, int start) {
        int xor = 0;
        int[] nums = new int[n];
        for(int i = 0;i<n;i++){
            nums[i] = start+2*i;
            int  current_element = nums[i];
            xor^=current_element;
        }
        return xor;
    }
}