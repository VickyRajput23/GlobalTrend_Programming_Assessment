#include <iostream>
#include <algorithm>
#include <climits> 
using namespace std;

// Definition
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        maxGain(root);
        return maxSum;
    }

private:
    int maxSum;
    int maxGain(TreeNode* node) {
        if (!node) return 0;
        
        int leftGain = max(maxGain(node->left), 0);
        int rightGain = max(maxGain(node->right), 0);
        
        int priceNewpath = node->val + leftGain + rightGain;
        
        maxSum = max(maxSum, priceNewpath);

        return node->val + max(leftGain, rightGain);
    }
};
int main() {
    // Example :
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);

    Solution solution;
    int result = solution.maxPathSum(root);
    cout << "Maximum Path Sum: " << result << endl;

    // Clean up the allocated nodes (not necessary for this example, but good practice)
    delete root->left;
    delete root->right;
    delete root;

    return 0;
}
