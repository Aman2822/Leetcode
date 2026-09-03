class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minEle = *min_element(begin(nums1) , end(nums1));

        if(minEle % 2 == 1){  // If the minele is odd then we can always make all elements odd
            return true;
        }
 
        //Check if we can make all even if there is odd then it will surely not an minimum element so we can't make it even 
        for(int &num : nums1){
            if(num % 2 == 1){
                return false;
            }
        }

        return true;
    }
};