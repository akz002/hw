// https://leetcode.com/problems/maximum-depth-of-binary-tree/description/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    int max = 0;
    int n = 0;
    if (root == NULL)
        return 0;
    findDepth(root, n, &max);
    return max;
}


void findDepth(struct TreeNode* node, int depth, int *max_depth)
{
    depth++;
    if (node->left != NULL)
        findDepth(node->left, depth, max_depth);
    else {
        if (depth > *max_depth)
            *max_depth = depth;
    }
    if (node->right != NULL)
        findDepth(node->right, depth, max_depth);
    else {
        if (depth > *max_depth)
            *max_depth = depth;
    }
}