class Solution {
public:
    bool anagram(string &s ,string &p){
        int arr[26] = {0};
        int nums[26] = {0};

        for(char &ch : s){
            arr[ch - 'a']++;
        }

        string formed = " ";

        for(int i = 0 ; i < 26 ; i++){
            int freq = arr[i];

            if(freq > 0){
                formed += string(freq , i+'a');
            }
        }

        for(char &ch : p){
            nums[ch - 'a']++;
        }

        string formed1 = " ";

        for(int i = 0 ; i < 26 ; i++){
            int freq = nums[i];

            if(freq > 0){
                formed1 += string(freq , i+'a');
            }
        }

        if(formed == formed1) return true;

        return false;
    }


    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        vector<string> ans;
        ans.push_back(words[0]);

        for(int i = 1 ; i < n ; i++){
            string curr = words[i];
            string prev = words[i-1];

            bool check = anagram(curr , prev);

            if(!check){
                ans.push_back(curr);
            }
        }

        return ans;
    }
};