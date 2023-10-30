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
public:
    vector<vector<int>> levelOrder(TreeNode *root)
    {
        vector<vector<int>> ans;
        if (!root)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        while (!q.empty())
        {
            int sz = q.size();
            vector<int> v;
            while (sz--)
            {
                TreeNode *f = q.front();
                v.push_back(q.front()->val);
                q.pop();
                if (f->left)
                    q.push(f->left);
                if (f->right)
                    q.push(f->right);
            }
            ans.push_back(v);
        }
        return ans;
    }
};
// class Solution {
// public:
//     vector<vector<int>> levelOrder(TreeNode* root) {
//         vector <vector<int>> ans;
//         if(!root)
//         {
//             return ans;
//         }
//         queue <pair<TreeNode*, int>> q;
//         q.push({root, 0});
//         while(!q.empty())
//         {
//             TreeNode *fr = q.front().first;
//             int level = q.front().second;
//             if(fr->left)
//             {
//                 q.push({fr->left, level+1});
//             }
//             if(fr->right)
//             {
//                q.push({fr->right, level+1});
//             }
//             if(level+1 > ans.size())
//             {
//                 ans.push_back({});
//             }
//             ans[level].push_back(fr->val);
//             q.pop();
//         }
//         return ans;
//     }
// };