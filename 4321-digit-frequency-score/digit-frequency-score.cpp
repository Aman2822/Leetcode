class Solution {
public:
    int digitFrequencyScore(int n) {
        
        unordered_map<int , int> mp;
        int temp = n;

        while(temp > 0){
           int rem = temp % 10;
           mp[rem]++;
           temp /= 10;
        }

        int ans = 0;

        for(auto it : mp){
           int ele = it.first;
           int freq = it.second;

           ans += (ele * freq);
        }

        return ans;
    }
};