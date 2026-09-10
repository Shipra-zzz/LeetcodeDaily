// https://leetcode.com/problems/count-nodes-equal-to-average-of-subtree/description/?envType=daily-question&envId=2026-09-10

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int sum=0;

    pair<int,int> help (TreeNode* node){
        if(node==NULL)  return {0,0};
        auto [ls,lc] =help(node->left);
        auto [rs, rc]= help(node->right);
        int cnt = lc+rc+1;
        int sum =rs+ls+node->val;
        if(sum/cnt == node->val)    sum++;
        return {sum,cnt};
    }
    int averageOfSubtree(TreeNode* root) {
        help(root);
        return sum;
    }
};
