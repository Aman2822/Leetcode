class Solution {
public:
    bool sumGame(string num) {
        int n = num.length();

        int leftKnownSum = 0 , rightKnownSum = 0;
        int leftQuesMarkCount = 0 , rightQuesMarkCount = 0;

        // We will get count of quesmark and sum
        for(int i = 0 ; i < n ; i++){
            if(num[i] == '?'){
                if(i < n/2 ){
                    leftQuesMarkCount++;
                }
                else{
                    rightQuesMarkCount++;
                }
            }
            else{
                if(i < n / 2){
                    leftKnownSum += num[i] - '0';
                }
                else{
                    rightKnownSum += num[i] - '0';
                }
            }
        }

        int totalQuesCount = leftQuesMarkCount + rightQuesMarkCount;
        
        //If the totalQues mark count is odd then alice always wins because it will break Bob's nullify part
        if(totalQuesCount % 2 != 0) return true;

        // This case is when ques mark is on same side then if alice try x to denote a ? then bob eill denote the ? as '9-x'
        // Suppose there are 6 ques on left side then:
        // Alice-> x   Bob-> 9-x
        // Alice-> y   Bob-> 9-y
        // Alice-> z   Bob-> 9-z
        // total = 27/6 = 4.5 
        // this is an general formula that we have generated

        int left = leftKnownSum + (4.5 * leftQuesMarkCount );
        int right = rightKnownSum + (4.5 * rightQuesMarkCount);

        if(left == right) return false;
        else return true;
    }
};