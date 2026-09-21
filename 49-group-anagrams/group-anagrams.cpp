class Solution {
public:
    string anagram(string curr){
        int arr[26] = {0};

        for(char &ch : curr){
            arr[ch - 'a']++;
        }

        string formed = "";

        for(int i = 0 ; i < 26 ; i++){
            int freq = arr[i];

            if(freq > 0){
                formed += string(freq , i + 'a');
            }
        }

        return formed;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        vector<vector<string>> ans;

        // //Approach I - sort internally
        
        // unordered_map<string , vector<string>> mp;

        // for(const string &s : strs ){
        //     string key = s;
        //     sort(key.begin() , key.end());
        //     mp[key].push_back(s);
        // }

        // for(auto it : mp){
        //     ans.push_back(it.second);
        // }

        // return ans;

        //Approach 2 - without sorting
        unordered_map<string , vector<string>> mp;

        for(string &s : strs){
           string curr = s;

           string formed = anagram(curr);

           mp[formed].push_back(curr);
        }

        for(auto it : mp){
            ans.push_back(it.second);
        }

        return ans;



    }
};