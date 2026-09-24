class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        if(n == 1) return pref;

        vector<int> org;
        org.push_back(pref[0]);

        for(int i = 1 ; i < n ; i++){
           int val = pref[i] ^ pref[i-1];
           org.push_back(val);
        }

        return org;
    }
};