class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
      sort(strs.begin() , strs.end());

      string first = strs.front();
      string last = strs.back();

      string result = "";

      int min_len = min(first.length() , last.length());

      for(int i = 0 ; i < min_len ; i++){
        if(first[i] == last[i] ){
            result += first[i];
        }
        else{
            break;
        }
      }

      return result;

    }
};