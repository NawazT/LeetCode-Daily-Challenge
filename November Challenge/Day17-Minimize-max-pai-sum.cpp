// Key Points - Max element will give min sum when paired with min element
// sorting the elements and pairing from one element from each end will result in optimal pair up

// TC - O(NlogN)
// SC - O(1)

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //return (*min_element(nums.begin(), nums.end()) + *max_element(nums.begin(), nums.end()));
        sort(nums.begin(), nums.end());
        int ans = INT_MIN;
        int n = nums.size();
        for(int i=0,j=n-1; i<j; i++,j--)
        {
            ans = max(nums[i] + nums[j], ans);
        }
        return ans;
    }
};