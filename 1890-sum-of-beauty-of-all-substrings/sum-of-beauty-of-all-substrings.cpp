class Solution {
public:
    int beauty(string curr){
        int n = curr.length();
        int freq[26] = {0};

        for(char &ch : curr){
            freq[ch - 'a']++;
        }

        int maxfreq = INT_MIN;
        int minfreq = INT_MAX;

        for(int i = 0 ; i < 26 ; i++){
            if(freq[i] > 0){
                maxfreq = max(maxfreq , freq[i]);
                minfreq = min(minfreq , freq[i]);
            }
        }

        if(maxfreq == INT_MIN || minfreq == INT_MAX) return 0;

        return maxfreq - minfreq;
    }


    int beautySum(string s) {
        int n = s.length();
        vector<string> substrings;
        int ans = 0;

        for(int i = 0 ; i < n ; i++){
            string temp = "";
            for(int j = i ; j < n ; j++){
                temp += s[j];
                if(temp.length() > 2){
                    substrings.push_back(temp);
                }
            }
        }

        for(int i = 0 ; i < substrings.size(); i++){
            int curr = beauty(substrings[i]);
            ans += curr;
        }

        return ans;
    }
};