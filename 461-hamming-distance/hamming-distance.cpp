class Solution {
public:
    int hammingDistance(int x, int y) {
       int n =  x ^ y; 

       int cnt = 0;

       while(n > 1){
        cnt += n & 1;
        n /= 2;
       }
       if(n == 1) cnt++;

       return cnt;
    }
};