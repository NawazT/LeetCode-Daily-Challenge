// Recursive

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
    void solve(TreeNode* root, vector<int> &in) {
        if(root == NULL) return;

        solve(root->left, in);
        in.push_back(root->val);
        solve(root->right, in);
    }
    vector<int> inorderTraversal(TreeNode* root) {
        if(root == NULL) return {};

        vector<int> in;

        solve(root, in);

        return in;

    }
};

//Iterative

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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        if(!root) return in;

        TreeNode* curr = root;

        while(curr)
        {
            TreeNode* l = curr->left;
            if(!l)
            {
                in.push_back(curr->val);
                curr = curr->right;
            }
            else
            {
                bool flag = true;
                while(l->right)
                {
                    if(l->right == curr)
                    {
                        l->right = NULL;                            
                        in.push_back(curr->val);
                        curr = curr->right;
                        flag = false;
                    }
                    else l = l->right;
                }
                if(flag)
                {
                    l->right = curr;
                    curr = curr->left; 
                }
            }
        }
        return in; 
    }
};

// Morris Traversal

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

 // Morris Traversal
 // Uses the concept of threaded binary tree
 // Threaded B-Tree -> empty right pointers are used to connect child to parent in order to achieve the desired traversal method.
 // TC ~ O(3*N)
 // SC = O(1)

class Solution {
public:
    TreeNode* getRightMost(TreeNode* l, TreeNode* curr) {
        while(l->right)
        {
            if(l->right == curr)
            {
                return l;
            }
            else l = l->right;
        }
        return l;
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> in;
        if(!root) return in;

        TreeNode* curr = root;

        while(curr)
        {
            TreeNode* l = curr->left;
            if(!l)
            {
                in.push_back(curr->val); //left subtree is complete
                curr = curr->right;
            }
            else
            {
                TreeNode* r = getRightMost(l, curr);
                
                if(r->right == NULL) // Create the thread from right child to parent
                {
                    r->right = curr;
                    curr = curr->left; 
                }
                else // Destroy the thread created earlier 
                {
                    r->right = NULL;                            
                    in.push_back(curr->val); //left subtree is complete
                    curr = curr->right;
                }
            }
        }
        return in; 
    }
};