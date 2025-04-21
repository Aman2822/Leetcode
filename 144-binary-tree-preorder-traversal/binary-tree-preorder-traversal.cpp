class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
    vector<int> result;
    function<void(TreeNode*)> dfs = [&](TreeNode* node) {
        if (node == nullptr) return;
        result.push_back(node->val); // Visit node
        dfs(node->left); // Traverse left subtree
        dfs(node->right); // Traverse right subtree
    };

    dfs(root);
    return result;
}

};