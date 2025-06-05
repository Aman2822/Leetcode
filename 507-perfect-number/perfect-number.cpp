class Solution {
public:
    bool checkPerfectNumber(int num) {
       /* int sum = 0;
        for(int i=1;i< num;i++){
            if(num%i==0){
                sum += i;
            }
        } */
        if(num<=1) return false;
        int sum=1;
        for(int i=2;i*i<num;i++){
            if(num%i==0){
                sum+=i;  //adding divisor
                if(num!=sum) sum+=num/i;  //adding quotient
            }
        }
        if(num==sum) return true;
        else return false;
    }
};