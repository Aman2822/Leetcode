class Solution {
public:
    int digitProd(int num){
        int prod = 1;

        while( num > 0){
            int rem = num % 10;
            prod *= rem;
            num /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int ans = n ;
        
        for(int i = n ; i < 101 ; i++){
            int sum = digitProd(i);
            if(sum % t == 0){
                ans = i;
                break;
            }
        }
        return ans;
    }
};