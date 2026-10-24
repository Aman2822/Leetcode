class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice, string arriveBob, string leaveBob) {

        string arrive = max(arriveAlice , arriveBob);
        string dep = min(leaveAlice , leaveBob);

        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        auto getDays = [&](string date){
            int m = stoi(date.substr(0 , 2));
            int d = stoi(date.substr(3 , 2));

            int total = 0;
            for(int i = 0 ; i < m-1; i++){
                total += days[i];
            }

            return total + d;
        };

        int start = getDays(arrive);
        int end = getDays(dep);

        return max(0 , end - start + 1);
        
    }
};