// TC = O(N)
// SC = O(N)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        vector<int> pre(n,0);
        pre[0] = nums[0];

        for(int i=1;i<n; i++)
        {
            pre[i] = pre[i-1] + nums[i];
        }

        for(int i=0;i<n;i++)
        {
            int leftSum = (pre[i] - nums[i]);
            int rightSum = (pre[n-1] - pre[i]);
            ans[i] = (nums[i] * i) - leftSum + rightSum - (nums[i] * (n-i-1));            
        }

        return ans;
    }
};

// TC = O(N)
// SC = O(1)

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n,0);
        //vector<int> pre(n,0);
        int sum = nums[0];

        //pre[0] = nums[0];

        for(int i=1;i<n; i++)
        {
           // pre[i] = pre[i-1] + nums[i];
           sum+=nums[i];
        }

        int leftSum = 0;
        int rightSum = sum;
        for(int i=0;i<n;i++)
        {
            rightSum = sum - leftSum - nums[i];
            ans[i] = (nums[i] * i) - leftSum + rightSum - (nums[i] * (n-i-1));
            leftSum+=nums[i];            
        }

        return ans;
    }
};