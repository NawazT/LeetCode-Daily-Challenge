// Approach 1

/**
 * Definition for a binary tree node. */
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
    };
 
class Solution {
public:
    unordered_map<int,int> mpp;

    void dfs(TreeNode* root) {
        if(root == NULL)
        {
            return;
        }

        mpp[root->val]++;

        dfs(root->left);
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        mpp.clear();
        dfs(root);

        vector<pair<int,int>> v;

        for(auto &it:mpp)
        {
            v.push_back({it.first,it.second});
        }

        auto lamda = [] (pair<int,int> a, pair<int,int> b) {
            return a.second > b.second;
        };

        sort(begin(v), end(v), lamda);

        vector<int> ans;
        int currMax = v[0].second;

        for(auto it : v)
        {
            if( it.second >= currMax)
            {
                ans.push_back(it.first);
            } 
        }

        return ans; 
    }
};

//TC = O(N)
//sc = O(N)

//apporach 2 - Optimal

//TC = O(N)
//SC = O(N)

class Solution {
public:
    int currNum = 1e5 + 1, currFreq = 0, maxFreq = 0;
    vector<int> res;

    void dfs(TreeNode* root) {
        if(root==NULL) return;

        dfs(root->left);

        if(root->val != currNum)
        {
            currNum = root->val;
            currFreq = 1;
        }
        else
        {
            currFreq++;
        }

        if(currFreq > maxFreq)
        {
            maxFreq = currFreq;                
            res = {};
            res.push_back(currNum);            
        }
        else if(currFreq == maxFreq)
        {
            res.push_back(currNum);
        }
        dfs(root->right);
    }

    vector<int> findMode(TreeNode* root) {
        dfs(root);
        return res;
    }
};