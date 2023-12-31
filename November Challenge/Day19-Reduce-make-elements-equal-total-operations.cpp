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

// All elements right to nextL are greater so,
// we need n-1-nextL operations to make all elements to the right equal
// TC = O(NlogN)
// SC = O(1)

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        //sorting to select nextl and l;
        sort(nums.begin(), nums.end());

        int n = nums.size();
        int l = nums[n-1];
        int nextL = n-1;
        int ops = 0;

        while(nextL >= 0)
        {
            if(nums[nextL] == l)
            {
                nextL--;
            }
            else{
                ops+=(n-1-nextL);
                l = nums[nextL];
            }
        }
        return ops;
    }
};
// Optimal Approach
// TC = O(N)
// SC = O(1) -> fixed size freq array
//storing freq of each in an array
//iterating from last first non zero freq will be largest

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        

        vector<int> freq(50001,0);

        for(int &i : nums)
        {
            freq[i]++;
        }

        int n = nums.size();
        int l = -1;
        int nextL = -1;
        int ops = 0;

        for(int j = 50000; j>=0; j--)
        {
            if(freq[j] > 0)
            {
                l = j;
                nextL = j;
                break;
            } 
        }


        while(nextL >= 0)
        {
            if(nextL == l || freq[nextL] == 0)
            {
                nextL--;
            }
            else{
                ops+=freq[l];
                freq[nextL]+=freq[l];
                l = nextL;
            }
        }
        return ops;
    }
};