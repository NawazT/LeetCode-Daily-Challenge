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

//Optimal approach
// Hashing and keep count of each element find out min and max, 
// keep pairing min and max and decresing the count if finished dec the max or increase the min by 1
// N ranges from 1 to 100000 so does N[i] so, this willl take constant space
// TC O(N)
// Sc O(1)

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        //return (*min_element(nums.begin(), nums.end()) + *max_element(nums.begin(), nums.end()));
        //sort(nums.begin(), nums.end());
        int mx = INT_MIN;
        int mn = INT_MAX;
        int n = nums.size();

        vector<int> mpp (100001, 0);

        for(int i=0;i<n;i++)
        {
            mpp[nums[i]]++;
            mx = max(mx, nums[i]);
            mn = min(mn, nums[i]);
        }

        int l = mn, h = mx;
        mx = INT_MIN;

        while(l<=h)
        {
            if(mpp[l] == 0)l++;
            else if(mpp[h] == 0) h--;
            else
            {
                mx = max(mx, l+h);
                mpp[l]--;
                mpp[h]--;
            }
        }

        return mx;
    }
};