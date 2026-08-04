class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> miss_elements;
        unordered_set<int> temp(nums.begin() , nums.end());
        
        // int max_ele = *max_element(nums.begin() , nums.end());
        // int min_ele = *min_element(nums.begin() , nums.end());
        int max_ele = INT_MIN, min_ele = INT_MAX;

        for(int i = 0 ; i < n ; i++){
           max_ele = max(max_ele, nums[i]);
        }

        for(int i = 0 ; i < n ; i++){
           min_ele = min(min_ele, nums[i]);
        }

        for(int i = min_ele + 1 ; i < max_ele ; i++){
            if(temp.find(i) == temp.end()){
               miss_elements.push_back(i);
            }
        }

        return miss_elements;

        

        
    
    }
};