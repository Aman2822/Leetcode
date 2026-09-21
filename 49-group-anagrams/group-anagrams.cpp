class Solution {
public:
   /*
   humlog sabka ascii vlaue nikal sakte hai and pair kar sakte hai and fir jiska values equal usko ek array mein dal ke push kar sakte hai 
   */
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        //Approach I - sort internally
        
        unordered_map<string , vector<string>> mp;

        for(const string &s : strs ){
            string key = s;
            sort(key.begin() , key.end());
            mp[key].push_back(s);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;

    }
};