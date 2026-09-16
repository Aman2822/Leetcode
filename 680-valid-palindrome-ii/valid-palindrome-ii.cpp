class Solution {
public:
    bool validPalindrome(string s) {
        int i = 0 , j = s.length() - 1;
        int idx = -1 ,  idx2 = -1;

        while(i < j){
           if(s[i] != s[j]){
            idx = i;
            idx2 = j;
            break;
           }
           i++;
           j--;
        }

        if(idx == -1 && idx2 == -1) return true;
        int left_s = -1 , right_s = -1;

        if(idx != -1){
            string res = "";
            for(int i = 0 ; i < s.length() ; i++){
                if(i == idx){
                    continue;
                }
                res += s[i];
            }

            int i = 0 , j = res.length() - 1;
            while(i < j){
                if(res[i] != res[j]){
                    left_s = i;
                    break;
                }
                i++;
                j--;
            }
        }

        if(idx2 != -1){
            string res2 = "";
            for(int i = 0 ; i < s.length() ; i++){
                if(i == idx2){
                    continue;
                }
                res2 += s[i];
            }

            int i = 0 , j = res2.length() - 1;
            while(i < j){
                if(res2[i] != res2[j]){
                    right_s = i;
                    break;
                }
                i++;
                j--;
            }
        }

        // cout << left_s << "" << right_s << endl;

        if(left_s == -1 ||  right_s == -1) return true;

        return false;
    }
};