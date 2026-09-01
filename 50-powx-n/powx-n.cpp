class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long long exponent = n;

        if(exponent < 0){
            exponent = -1 * exponent;
        }

        while (exponent > 0) {
            // If exponent is odd
            if (exponent % 2 == 1) {
                ans = ans * x;
                exponent = exponent - 1;
            } else {
                // If even
                x = x * x;
                exponent  = exponent /2;
            }
        }

        if(n < 0){
            ans = 1.0/ans;
        }


        return ans;
    }
};