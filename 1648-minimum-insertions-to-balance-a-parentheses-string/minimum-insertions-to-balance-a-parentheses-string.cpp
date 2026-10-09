class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        int result = 0;
        int count = 0;
        int i = 0;

        while(i < n){
            if(s[i] == '('){   //whenever we see a opening then increase count and increment
                count++;
                i++;
            }
            else{  // for closing bracket
                if(count > 0){   // count > 0 means there is an opening if not then insert
                   count--;
                }
                else{
                    result++;
                }

                if(i+1 <n && s[i+1] == ')'){   //check i+1 is an closing if not then insert
                    i += 2;
                }
                else{
                    result++;
                    i++;
                }
            }
        }

        return result + (count * 2);   //if there are remaining opening multiply by 2 closing brack
    }
};