class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.length();
        vector<int> freq(26,0);
        vector<bool> taken(26,false);
        string result = "";

       //Marked last apperances
        for(int i = 0 ; i < n ;i++){
            char ch = s[i];
            freq[ch -'a'] = i;
        }

        for(int i = 0 ; i < n ;i++){
            char ch = s[i];

            int idx = ch - 'a';
            
            //If any char is seen skip it
            if(taken[idx] == true) continue;

            //For every character see the previous character it is lesser than it and if not then pop only when the previous char is present in future otherwise not and if present it and mark it false and pop it repeat until the previous element is smaller than current element
            while(result.length() > 0 && result.back() > ch && freq[result.back()- 'a'] > i  ){
                taken[result.back() - 'a'] = false;
                result.pop_back();
            }

            result += s[i];
            taken[ch - 'a'] = true;
        }
        return result;


    }
};