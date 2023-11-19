// TC = O(NlogN)
// SC = O(N)

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //sorting to select nextl and l;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = nums[n-1];

        unordered_map<int,int> mpp;

        for(auto &it : nums)
        {
            mpp[it]++;
        }

        int nextL = n-1;
        int ops = 0;
        while(nextL >= 0)
        {
            if(nums[nextL] == l)
            {
                nextL--;
            }
            else{
                ops+=mpp[l];
                mpp[nums[nextL]]+=mpp[l];
                l = nums[nextL];
            }
        }
        return ops;
    }
};

