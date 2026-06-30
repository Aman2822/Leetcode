class Solution {
public:
    string largestGoodInteger(string num) {
        int n = num.length();
        string ans = "";
        int i = 0 , j = 1, k = 2;

        while(k < n){
            if(num[i] == num[j] && num[j] == num[k]){
                string current_triplet = num.substr(i,3);

                if(current_triplet > ans ){
                    ans = current_triplet;
                }
            }
            i++;
            j++;
            k++;
        }
        return ans;

    }
};