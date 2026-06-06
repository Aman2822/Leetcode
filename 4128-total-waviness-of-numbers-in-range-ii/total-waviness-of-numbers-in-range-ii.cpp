class Solution {
public:
    typedef long long ll;
    int n;
    string s;

    ll dpTotalNumbers[16][10][10];
    ll dpTotalWaviness[16][10][10];

    pair<ll,ll> solve(int curr, int prevprev, int prev, bool isLimitedActualnumber , bool isLeadingZeros){
        if(curr == n){
            return {1 , 0};    // totalNumbers, totalWaveScore
        }

        if(!isLimitedActualnumber && !isLeadingZeros && prevprev>=0 && prev>=0 ){
            if(dpTotalNumbers[curr][prevprev][prev] !=-1 && dpTotalWaviness[curr][prevprev][prev] ){
                return {dpTotalNumbers[curr][prevprev][prev], dpTotalWaviness[curr][prevprev][prev]};
            }
        }

        ll totalNumbers = 0;
        ll totalWaveScore = 0;

        int limitdigit = isLimitedActualnumber ? (s[curr] - '0') : 9;

        for(int digit = 0; digit<=limitdigit ; digit++){
           bool newIsLeadingZeros = isLeadingZeros && (digit==0);

           int newprevprev = prev ;
           int newprev = newIsLeadingZeros ? -1: digit;

           auto[remainTotalnumbers, reaminTotalWavescore ] = solve(curr+1, newprevprev, newprev , 
                                  isLimitedActualnumber && (digit == limitdigit), newIsLeadingZeros);

           if(!newIsLeadingZeros && prevprev>=0 && prev>=0){
            bool isPeak = (prevprev < prev && prev > digit);
            bool isValley = (prevprev >prev && prev < digit);

            if(isPeak || isValley){
                totalWaveScore += remainTotalnumbers;
            }
           }
           totalNumbers += remainTotalnumbers;
           totalWaveScore += reaminTotalWavescore;
        }
        if(!isLimitedActualnumber && !isLeadingZeros && prevprev>=0 && prev>=0){
            dpTotalNumbers[curr][prevprev][prev] = totalNumbers;
            dpTotalWaviness[curr][prevprev][prev] = totalWaveScore;
        }

        return {totalNumbers, totalWaveScore};
    }

    ll func(ll num){
        if(num < 100){  //number should be of 3 digits
            return 0;
        }

        memset(dpTotalNumbers, -1, sizeof(dpTotalNumbers));
        memset(dpTotalWaviness, -1, sizeof(dpTotalWaviness));

        s = to_string(num);
        n = s.length();

        auto[totalNumbers, totalWaveScore] = solve(0,-1,-1,true, true);

        return totalWaveScore;

    }

    long long totalWaviness(long long num1, long long num2) {
        return func(num2) - func(num1-1);
    }
};