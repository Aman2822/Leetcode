class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int l = s.length();
        vector<int> zero_pairs;

        int active_ones = count(s.begin() ,s.end() , '1');

        int i = 0;
        while(i < l){
            if(s[i] == '0'){
                int start = i ;
                while(i < l  && s[i] == '0') i++;

                zero_pairs.push_back(i-start);
            }
            else{
                i++;
            }
        }
        int n = zero_pairs.size();
        int max_sum = 0;
        for(int i = 1 ;  i < n ; i++){
            max_sum = max(max_sum , zero_pairs[i] + zero_pairs[i-1]);
        }
        
        return max_sum + active_ones;




       

    }
};