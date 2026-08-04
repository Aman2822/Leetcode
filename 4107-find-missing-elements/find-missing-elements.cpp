class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> miss_elements;
        vector<int> arr_Ele;
        unordered_set<int> temp(nums.begin() , nums.end());
        
        int max_ele = *max_element(nums.begin() , nums.end());
        int min_ele = *min_element(nums.begin() , nums.end());

        for(int i = min_ele + 1 ; i < max_ele ; i++){
            if(temp.find(i) != temp.end()){
                arr_Ele.push_back(i);
            }
            else{
                miss_elements.push_back(i);
            }
        }

        return miss_elements;

        

        
    
    }
};