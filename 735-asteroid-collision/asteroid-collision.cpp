class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n = asteroids.size();
        vector<int> ans;

        for(int i = 0 ; i < n ; i++){
            //whenever the asteroids are +ve we dont need to worry only push it
            if(asteroids[i] > 0){
                ans.push_back(asteroids[i]);
            }
            else{
                //pop the +ve elements until the curr is greater than prev element
                while(!ans.empty() && ans.back() > 0 && ans.back() < abs(asteroids[i])){
                    ans.pop_back();
                }
                //if both equal destroy both
                if(!ans.empty() && ans.back() > 0 && ans.back() == abs(asteroids[i])){
                    ans.pop_back();
                }
                //if stack empty then -ve element  will be safe or the prev is -ve so we can push the -ve asteroid
                else if(ans.empty() || ans.back() < 0){
                    ans.push_back(asteroids[i]);
                }
            }
        }

        return ans;
    }
};