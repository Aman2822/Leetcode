class Solution {
    public boolean isPowerOfFour(int n) {

        return (Math.log(n)/Math.log(4)) % 1 == 0;
      /*  if(n == 0) return false;
        if(n == 1) return true;

       
            if(n % 4 == 0){
                n /= 4;
                return true;
            } 
        
        return  n == 1; */
    }
}