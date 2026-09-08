class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        int n = arr.size();
        unordered_map<int , int> mp;

        for(int i = 0 ; i < n ; i++ ){
            mp[arr[i]]++;
        }
        int i = 1;
        int ans = -1;
        while(k > 0){
            if(mp.find(i) == mp.end()){
                ans = i;
                k--;
            }
            i++;
        }

        return ans;

    }
};