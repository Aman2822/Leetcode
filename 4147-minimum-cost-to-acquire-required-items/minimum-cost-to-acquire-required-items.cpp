class Solution {
public:
    /*
    the common ke liye dono min nikal le min of cost lo both wala and cost1 + cost2;
    */

    typedef long long ll;

    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        ll res = 0;

        res = 1LL*  min(need1 , need2) * min(cost1 + cost2 , costBoth);

        ll rem1 = need1 - min(need1 , need2);
        ll rem2 = need2 - min(need1 , need2);

        if(rem1 > 0){
            res += 1LL *  rem1 * min(cost1 , costBoth);
        }
        else if(rem2 > 0){
            res += 1LL * rem2 * min(cost2 , costBoth);
        }

        return res;

    }
};