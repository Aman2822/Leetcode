class Solution {
public:
    bool rotateString(string s, string goal) {
        int s_len = s.length() , goal_len = goal.length();
        if(s_len != goal_len){
            return false;
        }

        char ch = s[0];

        for(int i = 0 ; i < s_len ; i++){
            if(ch == goal[i]){
                bool is_valid = true;

                for(int j = 0 ; j < s_len; j++){
                    char s_check = s[j];
                    int g_index =(i+j) % s_len;
                    char g_check = goal[g_index];
                    if(s_check != g_check){
                        is_valid = false;
                        break;
                    }
                }
                if(is_valid) return true;
            }
            
        }
        return false;
    }
};