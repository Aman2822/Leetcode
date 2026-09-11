class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        int n = digits.size();
        
        //Approach 1 - all possibilities
        // set<int> ans;
        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < n ; j++){
        //         for(int k = 0 ; k < n ; k++){
        //             if(i == j || j == k || i == k) continue;

        //             int num = (digits[i] * 100) + (digits[j] * 10) + digits[k];

        //             if(num > 99 &&  num % 2 == 0){
        //                 ans.insert(num);
        //             }
        //         }
        //     }
        // }

        // vector<int> result(ans.begin() , ans.end());

        // return result;

        //Approach 2 - Using map
        unordered_set<int> ans;
        vector<int> mp(10 , 0);  //Created a map with size 10 intilaized to 0
        
        for(int &nums : digits){
            mp[nums]++;
        }

        for(int i = 1 ; i <= 9 ; i++){
            if(mp[i] == 0) continue;
            mp[i]--;
            for(int j = 0 ; j <= 9 ; j++){
                if(mp[j] == 0) continue;
                mp[j]--;
                for(int k = 0 ; k <=8 ; k += 2){
                    if(mp[k] == 0) continue;
                    mp[k]--;

                    int num = (i * 100) + (j * 10) + k;
                    
                    if(num > 99 & num % 2 == 0){
                        ans.insert(num);
                    }

                    mp[k]++;
                }
                mp[j]++;
            }
            mp[i]++;
        }
        vector<int> result(ans.begin() , ans.end());
        sort(begin(result) , end(result));
        return result;
    }
};