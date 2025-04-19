class Solution {
public:
    string convertToBase7(int num) {
        // Handle the case for zero
        if (num == 0) return "0";
        
        // Handle the case for negative numbers
        bool isNegative = num < 0;
        num = abs(num);
        
        // Prepare to collect the result
        string result = "";
        
        // Perform the conversion
        while (num > 0) {
            result = to_string(num % 7) + result;  // Get the remainder and append to the result
            num /= 7;  // Update the number for the next iteration
        }
        
        // Add the negative sign if necessary
        if (isNegative) {
            result = "-" + result;
        }
        
        return result;
    }
};