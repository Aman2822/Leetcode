
class Solution {
public:
    void inOrderTraversal(TreeNode* root, unordered_map<int, int>& freqMap) {
        if (root == nullptr) return;
        
        // Traverse the left subtree
        inOrderTraversal(root->left, freqMap);
        
        // Process the current node
        freqMap[root->val]++;
        
        // Traverse the right subtree
        inOrderTraversal(root->right, freqMap);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> freqMap;
        
        // Perform in-order traversal to fill the frequency map
        inOrderTraversal(root, freqMap);
        
        // Find the maximum frequency
        int maxFreq = 0;
        for (const auto& entry : freqMap) {
            maxFreq = max(maxFreq, entry.second);
        }
        
        // Collect all the numbers that appear with the maximum frequency
        vector<int> result;
        for (const auto& entry : freqMap) {
            if (entry.second == maxFreq) {
                result.push_back(entry.first);
            }
        }
        
        return result;
    }
};