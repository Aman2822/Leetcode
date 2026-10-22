class Solution {
public:
    int sum(int n){
        int ans = 0;

        while(n > 0){
            ans += n % 10;
            n /= 10;
        }

        return ans;
    }
    int minElement(vector<int>& nums) {
        int n = nums.size();
        vector<int> replace;

        for(int i = 0 ; i < n ; i++){
            int val = sum(nums[i]);
            replace.push_back(val);
        }

        return *min_element(replace.begin() , replace.end());

    }
};