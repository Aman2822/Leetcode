class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n = digits.size();
        
        //Approach 1 - find all possibilites brute force
        set<int> ans;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < n ; j++){
                for(int k = 0 ; k < n ; k++){
                    if(i == j || j == k || i == k) continue;

                    int num = (digits[i] * 100) + (digits[j] * 10) + digits[k];

                    if(num > 99 &&  num % 2 == 0){
                        ans.insert(num);
                    }
                }
            }
        }

        // for(int i : ans){
        //     cout << i << endl;
        // }

        return ans.size();


    }
};