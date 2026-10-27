class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int m = nums2.size();


        //Approach 1 - brute force

        vector<int> res(m);

        // for(int i = 0 ; i < n ; i++){
        //     for(int j = 0 ; j < m ; j++){
        //         if(nums1[i] == nums2[j]){
        //             bool flag = false;
        //             for(j = j+1 ; j < m ; j++){
        //                 if(nums2[j] > nums1[i]){
        //                     flag = true;
        //                     res.push_back(nums2[j]);
        //                     break;
        //                 }
        //             }
        //             if(!flag) res.push_back(-1);
        //         }
        //     }
        // }

        // return res;


        //Approach 2 - Monotonic Stack
        stack<int> st;

        //traverse for nums2 and calculate its nge
        for(int i = m - 1 ; i >= 0 ;i--){
            while(!st.empty() && st.top() <= nums2[i]){
                st.pop();
            }

            if(!st.empty()){
                res[i] = st.top();
            }
            else res[i] = -1;

            st.push(nums2[i]);
        }

       //Map the elements with its nge
        unordered_map<int ,int> mp;
        for(int i = 0 ; i < m ; i++){
            mp[nums2[i]] = res[i];
        }

        vector<int> nge;
        for(int i = 0 ; i < n ; i++){
            nge.push_back(mp[nums1[i]]);
        }

        return nge;
    }
};