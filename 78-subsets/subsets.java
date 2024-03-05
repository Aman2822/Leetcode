import java.util.*;

class Solution {
    public List<List<Integer>> subsets(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        findSubsets(nums, new ArrayList<>(), ans, 0);
        return ans;
    }

    private void findSubsets(int[] nums, List<Integer> current, List<List<Integer>> ans, int start) {
        ans.add(new ArrayList<>(current));  
        for (int i = start; i < nums.length; i++) { 

            current.add(nums[i]);   //Include
            findSubsets(nums, current, ans, i + 1);

            current.remove(current.size() - 1);  //Exclude
        }
    }
}
