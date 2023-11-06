// Approach 1 - Brute Force
// TC = O(N^2);
// SC = O(1)

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

//Approach 2 - using Postorder
// TC = O(N)
// SC = O(1)

class Solution {
public:
    int res=0;
    pair<int,int> solve(TreeNode* root) {
        if(!root) return{0,0};

        pair<int,int> lp = solve(root->left);
        pair<int, int> rp = solve(root->right);

        int sum = root->val + lp.first + rp.first;
        int n = 1 + lp.second + rp.second;

        if(sum/n == root->val) res++;

        return {sum,n}; 
        
    }
    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return res;
    }
};