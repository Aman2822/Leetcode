class Solution {
public:
    bool checkString(string s) {
        vector<int> apos , bpos;

        for(int i = 0 ; i < s.length() ; i++){
            if(s[i] == 'a'){
              apos.push_back(i);
            }
            else{
                bpos.push_back(i);
            }
        }

        sort(apos.begin() , apos.end());
        sort(bpos.begin() , bpos.end());

        int n = apos.size();
        int m = bpos.size();

        if(n > 0 && m > 0){
            if(apos[n-1] > bpos[0]) return false;
        }
        return true;
    }
};