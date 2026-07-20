class Solution {
public:
    int differenceOfSums(int n, int m) {
        int divisible = 0 , non_divisible = 0;

        for(int i = 1 ; i<=n ;i++){
            if( i % m == 0) divisible += i;
            else non_divisible +=i;
        }

        return non_divisible - divisible;
    }
};