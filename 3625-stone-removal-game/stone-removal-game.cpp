class Solution {
public:
    bool canAliceWin(int n) {
        bool a = true;
        bool b = false;

        int curr = 10;

        while(n >= curr){
            if(a){
                n -= curr;
                curr--;
                if(n == 0) return true;
                a = false;
                b = true;
            }
            else if(b){
               n-= curr;
               curr--;
               if(n == 0) return false;
               a = true;
               b = false;
            }
        }

        if(a) return false;

        return true;

    }
};