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
    int cnt = 0;

    int solve(TreeNode* root, int &cnt) {
        if(!root) return 0;

        cnt++;

        int lsum = solve(root->left, cnt);
        int rsum = solve(root->right, cnt);

        return root->val+lsum+rsum;
    }

    void dfs(TreeNode* root) {
        if(!root) return;

        int n = 0;
        int sum = solve(root, n);

        if(root->val == sum/n) 
        {
            cout<<root->val << " ";
            cout<<sum/n<<endl;
            cnt+=1;
        }
        
        dfs(root->left);
        dfs(root->right);
    }

    int averageOfSubtree(TreeNode* root) {
        dfs(root);

        return cnt;
    }
};