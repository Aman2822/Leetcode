class Solution {
public:
    int digitSum(int n) {
        int sum = 0;
        while (n > 0) {
            int rem = n % 10;
            sum += rem;
            n /= 10;
        }
        return sum;
    }

    int digitProduct(int n) {
        int prod = 1;
        while (n > 0) {
            int rem = n % 10;
            prod *= rem;
            n /= 10;
        }

        return prod;
    }

    bool checkDivisibility(int n) {
        int sum = digitSum(n);
        int prod = digitProduct(n);

        int result = sum + prod;

        if(n % result == 0) return true;
        else return false;
    }
};