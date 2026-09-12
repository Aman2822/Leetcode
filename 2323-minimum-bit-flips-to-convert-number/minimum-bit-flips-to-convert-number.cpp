class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = start ^ goal;     //by xor we will get to know how many bits we have to change .. the bits we are change are going to be set

        int flip = 0 ;

        while(n > 1){           //We just count the set bits
            flip += n & 1;
            n /= 2;
        }
        if(n == 1) flip++;

        return flip;
        
    }
};