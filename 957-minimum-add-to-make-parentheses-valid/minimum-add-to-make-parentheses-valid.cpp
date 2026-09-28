class Solution {
public:
    int minAddToMakeValid(string s) {
        int n = s.length();
        int ans = 0;
        
        stack<char> st;
        st.push(s[0]);

        for(int i = 1 ; i < n ; i++){
            if(s[i] == '('){
                st.push(s[i]);
            }
            else{
                if(st.size() > 0 && st.top() == '('){
                    st.pop();
                }
                else{
                    ans++;
                }
            }
        }

        int rem = st.size();
        ans += rem;

        return ans;
    }
};