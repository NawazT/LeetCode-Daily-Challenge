class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<vector<int>> &ans, vector<int> &tmp) {
        ans.push_back(tmp);

        for(int i=ind; i<nums.size();i++)
        {
            if(i != ind && nums[i] == nums[i-1]) continue;
            tmp.push_back(nums[i]);
            solve(i+1, nums, ans, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> tmp;
        solve(0, nums, ans, tmp);
        return ans;
    }
};