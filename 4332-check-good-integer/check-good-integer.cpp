class Solution {
public:
    long digitSum(long p){
        int sum = 0;
        while(p>0){
            sum += p % 10;
            p /= 10;
        }
        return sum;
    }

    long squareSum(long b){
        int single_digit = 0;
        int square = 0;
        while(b>0){
            single_digit = b % 10;
            square += single_digit * single_digit;
            b/= 10;
        }
        return square;
    }
    
    bool checkGoodInteger(int n) {
       
        int good_int = 0;
        good_int = squareSum(n) - digitSum(n);

        if(good_int >=50){
            return true;
        }
        else{
            return false;
        }
    }
};