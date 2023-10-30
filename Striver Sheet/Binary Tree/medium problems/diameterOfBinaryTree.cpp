#include <bits/stdc++.h>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
class Solution
{
private:
    int height(TreeNode *root, int &maxi)
    {
        if (root == NULL)
            return 0;

        int lh = height(root->left, maxi);
        int rh = height(root->right, maxi);
        maxi = max(maxi, lh + rh);
        return 1 + max(lh, rh);
    }

public:
    int diameterOfBinaryTree(TreeNode *root)
    {
        int diameter = 0;
        height(root, diameter);
        return diameter;
    }
};