class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        // int n = nums1.size();
        // vector<int> nums2;

        // if (n == 1) {
        //     return true;
        // }

        // // Check only 1st and 2  elements;
        // if (nums1[0] % 2 != nums1[1] % 2) {
        //     for (int i = 0; i < n-1 ; i++) {
        //         if (nums1[i] % 2 == 1) {
        //             nums2.push_back(nums1[i]);
        //         } else {
        //             nums2.push_back(nums1[i] - nums1[i+1]);
        //         }
        //     }
        //     if (nums1[n-1] % 2 == 1) {
        //         nums2.push_back(nums1[n-1]);
        //     } else {
        //         nums2.push_back(nums1[n-2] - nums1[n-1]);
        //     }
        // }

        // if (nums1[0] % 2 == nums1[1] % 2) {
        //     for (int i = 0; i < n; i++) {
        //         nums2.push_back(nums1[i]);
        //     }
        // }

        // bool even = false;
        // bool odd = false;

        // for(int i = 0; i < nums2.size() ; i++){
        //     if(nums2[i] % 2 == 1){
        //         odd = true;
        //     }
        //     else{
        //         even = true;
        //     }
        // }

        // if(even && odd) return false;
        return true;
    }
};