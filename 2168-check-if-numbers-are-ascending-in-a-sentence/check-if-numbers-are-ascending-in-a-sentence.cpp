class Solution {
public:
    bool areNumbersAscending(string s) {
        int n = s.length();
        int i = 0;
        vector<int> numbers;

        while (i < n) {
            if (isdigit(s[i])) {
                int number = 0;
                while (i < n && isdigit(s[i])) {
                    number = number * 10 + (s[i] - '0');
                    i++;
                }
                numbers.push_back(number);
            }
            i++;
        }

        int j = 0;
        int p = numbers.size();
        while (j < p) {
            if (j+1 < p && numbers[j] >= numbers[j+1])
                return false;
            j++;
        }

        return true;
    }
};