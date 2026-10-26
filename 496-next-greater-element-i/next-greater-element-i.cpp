class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();
        vector<int> res;

        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(nums1[i] == nums2[j]){
                    bool flag = false;
                    for(j = j+1 ; j < m ; j++){
                        if(nums2[j] > nums1[i]){
                            flag = true;
                            res.push_back(nums2[j]);
                            break;
                        }
                    }
                    if(!flag) res.push_back(-1);
                }
            }
        }

        return res;
    }
};