class Solution {
public:
    bool haveConflict(vector<string>& event1, vector<string>& event2) {

        int e1_Start = ((event1[1][0] - '0') * 10 + (event1[1][1] - '0')) * 60;
        int e1_end =   (event1[1][3] - '0') * 10 + (event1[1][4] - '0');

        int e1_01 = e1_Start + e1_end;

        int e2_Start = ((event2[0][0] - '0') * 10 + (event2[0][1] - '0')) * 60;
        int e2_end =   (event2[0][3] - '0') * 10 + (event2[0][4] - '0');

        int e2_00 = e2_Start + e2_end;

        int e1_0 = ((event1[0][0] - '0') * 10 + (event1[0][1] - '0')) * 60;
        int e1_1 =   (event1[0][3] - '0') * 10 + (event1[0][4] - '0');

        int e1_00 = e1_0 + e1_1;

        int e2_1 = ((event2[1][0] - '0') * 10 + (event2[1][1] - '0')) * 60;
        int e2_0 =   (event2[1][3] - '0') * 10 + (event2[1][4] - '0');

        int e2_01 = e2_1 + e2_0;

        cout << e1_00 << " " << e1_01 << endl;
        cout << e2_00 << " " << e2_01 << endl;

        // cout << event1[0] <<  " " << event2[1] 
        // return event1[0] <= event2[1] && event2[0] <= event1[1];

        return e1_00 <= e2_01 && e2_00 <= e1_01; 

    }
};