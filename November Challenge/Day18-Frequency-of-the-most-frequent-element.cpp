// TC - O(NlogN)
// SC - O(N)

class Solution {
public:
    int bs(int targetInd, vector<int> &nums, int k, vector<long> &pre) {
        int l = 0;
        int r = targetInd;
        int res = -1;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            int count = targetInd - mid + 1;

            long windowSum = (long)count * (long)nums[targetInd];
            long originalSum = pre[targetInd] - pre[mid] + nums[mid];//computing window sum in O(1)

            int operations = windowSum - originalSum;

            if(operations > k)
            {
                //invalid mid, we can't increment every element from mid to target to nums[targetInd]
                l = mid+1;
            } 
            else
            {
                res = mid; //so it stores the smallest mid index at last, 
                //in order to maximize the count between mid to targetInd

                r = mid-1; // for possible better mid index
            }
        }
        return (targetInd-res+1);
    }

    int maxFrequency(vector<int>& nums, int k) {
        //Why Sorting ? -> We can only increment, so we go at each element and ask their smaller ones, 
        //can we increment them to make them equal to the current in <= k operations?   
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int freq = -1;
        vector<long> pre(n,0); // prefix sum
        pre[0] = nums[0];
        for(int i=1; i<n;i++)
        {
            pre[i] = pre[i-1]+nums[i];
        }

        //checking for the best target element by trying all element
        for(int i=n-1;i>=0;i--)
        {
            int curr = bs(i, nums, k, pre);
            freq = max(freq, curr);
        }

        return freq;
    }
};