class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {

        /*
        agar rec1 ka dono (x2,y2) bada hai rec2 ka(x1,y1) and
        rec2(x2,y2) agar bada hai rec1(x1,y1) if the these conditions satisfy means overlap
        */

        bool rec1_top = rec1[2] > rec2[0] && rec1[3] > rec2[1];
        bool rec2_top = rec2[2] > rec1[0] && rec2[3] > rec1[1];

        if(rec1_top && rec2_top) return true;

        return false;
       
    }
};