class Solution {
public:
    bool checkPerfectNumber(int num) {
        if (num <= 1) return false; // A perfect number is a positive integer greater than 1.
        
        int sum = 1; // 1 is always a divisor of any number, so we start with 1.
        
        // Iterate over numbers from 2 to sqrt(num)
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {  // i is a divisor of num
                sum += i;
                if (i != num / i) {  // Avoid adding the square root twice if it's perfect square
                    sum += num / i;
                }
            }
        }
        
        return sum == num; // Check if sum of divisors equals num
    }
};