class Solution {
    public boolean isPalindrome(int x) {
        if(x<0){
            return false;
        }
        long reverse = 0;
        int y = x;
        while(y>0){
            reverse = reverse *10 + y%10;
            y/=10;
        }
        return reverse == x;
    }
}