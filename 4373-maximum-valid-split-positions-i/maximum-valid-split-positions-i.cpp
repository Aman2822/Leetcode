class Solution {
public:
    int maxValidSplits(vector<int>& nums) {
        int n = nums.size();
        int score = 0;
        
        vector<int> pref1(n);
        pref1[0] = nums[0];
        for(int i = 1 ; i < n ; i++){
            pref1[i] = gcd(pref1[i-1] , nums[i]);
        }

        vector<int> suff1(n);
        suff1[n-1] = nums[n-1];
        for(int i = n-2 ; i >= 0 ; i--){
            suff1[i] = gcd(suff1[i+1] , nums[i]);
        }

         for(int k = 0 ; k < n - 1 ; k++){
                if(pref1[k] == suff1[k+1]){
                    score++;
                }
        }

        int score1 = 0;

        for(int i = 0 ; i < n ; i++){
            vector<int> arr;
            for(int j = 0 ; j < n ; j++){
                if(j == i) continue;
                arr.push_back(nums[j]);
            }
            int curr = 0;

            vector<int> pref(n-1);
            for(int k = 0 ; k < arr.size(); k++){
                if(k == 0) pref[k] = arr[0];
                else pref[k] = gcd(pref[k-1] , arr[k]); 
            }

            vector<int> suff(n-1);
            for(int k = arr.size() - 1 ;k >= 0; k--){
                if(k == arr.size() - 1) suff[k] = arr[arr.size()-1];
                else suff[k] = gcd(suff[k+1] , arr[k]); 
            }

            for(int k = 0 ; k < arr.size() - 1 ; k++){
                if(pref[k] == suff[k+1]){
                    curr++;
                }
            }

            score1 = max(score1 , curr);


        }

        return max(score , score1);

    }
};