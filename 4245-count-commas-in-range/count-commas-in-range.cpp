class Solution {
public: 
    int countCommas(int n) {
        if(n < 1000){
            return 0;
        }
        int number = n - 999;
        return number;

    }
};